#include "../headers/figuresManager.h"

#include <algorithm>
#include <iostream>

#include "../headers/inputValidator.h"

void figuresManager::addFigure() {
    int choice;
    std::cout << "\t(" << CIRCLE << ")Circle, (" << RECTANGLE << ")Rectangle, (" << TRIANGLE << ")Triangle: ";
    InputValidator::getInput<int>("", &choice);
    if (InputValidator::isError == false) {
        switch (choice) {
            case CIRCLE: this->addCircle(); break;
            case RECTANGLE: this->addRectangle(); break;
            case TRIANGLE: this->addTriangle(); break;
            default: std::cout << "Invalid choice" << std::endl; break;
        }
    }
}

void figuresManager::addCircle() {
    auto circle = cFabric.createFigure();
    if (circle != nullptr) {
        figures.push_back(circle);
        std::cout << "Circle added successfully" << std::endl;
    }
    else std::cout << "Circle could not be created" << std::endl;

}

void figuresManager::addRectangle() {
    auto rectangle = rFabric.createFigure();
    if (rectangle != nullptr) {
        figures.push_back(rectangle);
        std::cout << "Rectangle added successfully" << std::endl;
    }
    else std::cout << "Rectangle could not be created" << std::endl;
}

void figuresManager::addTriangle() {
    auto triangle = tFabric.createFigure();
    if (triangle != nullptr) {
        figures.push_back(triangle);
        std::cout << "Triangle added successfully" << std::endl;
    }
    else std::cout << "Triangle could not be created" << std::endl;
}

void figuresManager::printFigures() const {
    for (int i = 0; i < figures.size(); i++) {
        std::cout << i << ": ";
        this->figures.at(i)->printFigure();
    }
}

void figuresManager::printFiguresPerimeters() const {
    for (int i = 0; i < figures.size(); i++) {
        std::cout << i << ": ";
        this->figures.at(i)->printFigurePerimeter();
    }
}

void figuresManager::sortFigures() {
    std::sort(figures.begin(), figures.end(), [](const std::shared_ptr<Figure>& a, std::shared_ptr<Figure>& b) {return a->getPerimeter() < b->getPerimeter();});
    std::cout << "Figures sorted" << std::endl;
}

void figuresManager::deleteFigureByNumber() {
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

void figuresManager::deleteFiguresByPerimeter() {
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

void figuresManager::printPerimetersSum() const {
    double sum = 0;
    for (const auto & figure : figures) {
        sum += figure->getPerimeter();
    }
    std::cout << "Sum of perimeters: " << sum << std::endl;
}
