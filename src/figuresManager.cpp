#include "../headers/figuresManager.h"

#include <algorithm>
#include <iostream>
#include "../headers/constants.h"
#include "../headers/inputValidator.h"


FiguresManager::FiguresManager() {
    fabricFactory = std::make_unique<FabricsFactory>();
    actionMap[ADD_FIGURE] = make_pair("Add figure", [this] {addFigure(); });
    actionMap[OUTPUT_PARAM] = make_pair("Output a numbered list of figures with the shape type and its parameters", [this] {printFigures(); });
    actionMap[OUTPUT_PERIM] = make_pair("Output a numbered list of figures with the shape type and its perimeter", [this] {printFiguresPerimeters(); });
    actionMap[PRINT_PERIM_SUM] = make_pair("Print the sum of the perimeters of all figures", [this] {printPerimetersSum(); });
    actionMap[SORT_PERIM_ASC] = make_pair("Sort the figures in the collection in ascending order of perimeters", [this] {sortFigures(); });
    actionMap[DELETE_BY_NUM] = make_pair("Delete a figure from the collection by its number", [this] {deleteFigureByNumber(); });
    actionMap[DELETE_LARGER_PERIM] = make_pair("Delete figures whose perimeters are larger than the entered value", [this] {deleteFiguresByPerimeter(); });

    figureCreationMap[CIRCLE] = make_pair("Circle", [this] {addCircle(); });
    figureCreationMap[RECTANGLE] = make_pair("Rectangle", [this] {addRectangle(); });
    figureCreationMap[TRIANGLE] = make_pair("Triangle", [this] {addTriangle(); });
}


void FiguresManager::addFigure() {
    int choice;
    for (const auto& pair : figureCreationMap) {
        std::cout << pair.first << ".) " << pair.second.first << "\t";
    }
    std::cout << std::endl;
    InputValidator::getInput<int>("Enter witch figure you want to create: ", &choice);
    if (InputValidator::isError == false) {
        auto iter = figureCreationMap.find(choice);
        if (iter != figureCreationMap.end()) {
            iter->second.second();
        }
        else {
            std::cout << "No such figure" << std::endl;
        }
    }
}

void FiguresManager::addCircle() {
    auto circle = fabricFactory->createCircleFabric()->createFigure();
    if (circle != nullptr) {
        figures.push_back(circle);
        std::cout << "Circle added successfully" << std::endl;
    }
    else std::cout << "Circle could not be created" << std::endl;

}

void FiguresManager::addRectangle() {
    auto rectangle = fabricFactory->createRectangleFabric()->createFigure();
    if (rectangle != nullptr) {
        figures.emplace_back(rectangle);
        std::cout << "Rectangle added successfully" << std::endl;
    }
    else std::cout << "Rectangle could not be created" << std::endl;
}

void FiguresManager::addTriangle() {
    auto triangle = fabricFactory->createTriangleFabric()->createFigure();
    if (triangle != nullptr) {
        figures.push_back(triangle);
        std::cout << "Triangle added successfully" << std::endl;
    }
    else std::cout << "Triangle could not be created" << std::endl;
}

void FiguresManager::printFigures() const {
    for (int i = 0; i < figures.size(); i++) {
        std::cout << i << ": ";
        this->figures.at(i)->printFigure();
    }
}

void FiguresManager::printFiguresPerimeters() const {
    for (int i = 0; i < figures.size(); i++) {
        std::cout << i << ": ";
        this->figures.at(i)->printFigurePerimeter();
    }
}

void FiguresManager::sortFigures() {
    std::sort(figures.begin(), figures.end(), [](const std::shared_ptr<Figure>& a, std::shared_ptr<Figure>& b) {return a->getPerimeter() < b->getPerimeter();});
    std::cout << "Figures sorted" << std::endl;
}

void FiguresManager::deleteFigureByNumber() {
    int index;
    InputValidator::getInput<int>("Enter index of number to delete: ", &index);
    if (InputValidator::isError == false) {
        if (index >= 0 && index < figures.size()) {
            figures.erase(figures.begin() + index);
            std::cout << "Figure number " << index << " deleted successfully" << std::endl;
        }
        else std::cout << "Figure number " << index << " could not be deleted" << std::endl;
    }
}

void FiguresManager::deleteFiguresByPerimeter() {
    double perimeter;
    InputValidator::getInput<double>("Enter maximum perimeter for figures in container: ", &perimeter);
    if (InputValidator::isError == false) {
        if (perimeter >= 0) {
            for (int i = 0; i < figures.size(); i++) {
                if (figures.at(i)->getPerimeter() > perimeter)
                    figures.erase(figures.begin() + i);
            }
            std::cout << "Figures with perimeters more than " << perimeter << " deleted successfully" << std::endl;
        }
        else std::cout << "Perimeter could not be less then 0" << std::endl;
    }
}

void FiguresManager::printPerimetersSum() const {
    double sum = 0;
    for (const auto & figure : figures) {
        sum += figure->getPerimeter();
    }
    std::cout << "Sum of perimeters: " << sum << std::endl;
}
