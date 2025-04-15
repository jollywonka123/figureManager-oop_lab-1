#include "../headers/fabric.h"
#include "../headers/inputValidator.h"
#include "string"
#include "../headers/constants.h"
#include "../headers/dot.h"

std::shared_ptr<Figure> CircleFabric::createFigure() {
    double rad;
    std::shared_ptr<Figure> figure = nullptr;
    std::string creationName;
    std::string prompt = "Enter data for circle to create object - (Name Radius): ";
    InputValidator::getInput<std::string, double>(prompt, &creationName, &rad);
    if (InputValidator::isError == false)
        try {
            Dot centre("centre coordinate");
            figure = std::make_shared<Circle>(creationName, centre, rad);
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    return figure;
}

std::shared_ptr<Figure> RectangleFabric::createFigure() {
    std::string creationName;
    std::shared_ptr<Figure> figure = nullptr;
    std::string prompt = "Enter data for rectangle to create object - (Name): ";
    InputValidator::getInput<std::string>(prompt, &creationName);
    if (InputValidator::isError == false)
        try {
            Dot uLeft("upper left coordinate"), lRight("lower right coordinate");
            figure = std::make_shared<Rectangle>(creationName, uLeft, lRight);
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    return figure;
}

std::shared_ptr<Figure> TriangleFabric::createFigure() {
    std::string creationName;
    std::shared_ptr<Figure> figure = nullptr;
    std::string prompt = "Enter data for triangle to create object - (Name): ";
    InputValidator::getInput<std::string>(prompt, &creationName);
    if (InputValidator::isError == false)
        try {
            Dot c1("first coordinate"), c2("second coordinate"), c3("third coordinate");
            figure = std::make_shared<Triangle>(creationName, c1, c2, c3);
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    return figure;
}

std::shared_ptr<CircleFabric> FabricsFactory::createCircleFabric() {
    return std::make_shared<CircleFabric>();
}

std::shared_ptr<RectangleFabric> FabricsFactory::createRectangleFabric() {
    return std::make_shared<RectangleFabric>();
}

std::shared_ptr<TriangleFabric> FabricsFactory::createTriangleFabric() {
    return std::make_shared<TriangleFabric>();
}
