#include "../headers/fabric.h"
#include "../headers/inputValidator.h"
#include "string"
#include "../headers/constants.h"

std::shared_ptr<Figure> CircleFabric::createFigure() {
    double rad;
    Dot centre;
    std::shared_ptr<Figure> figure = nullptr;
    std::string creationName;
    std::string prompt = "Enter data for circle to create object - (Name X Y Radius): ";
    InputValidator::getInput<std::string, double, double, double>(prompt, &creationName, &centre.x, &centre.y, &rad);
    if (InputValidator::isError == false)
        try {
            figure = std::make_shared<Circle>(creationName, centre, rad);
        } catch (std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    return figure;
}

std::shared_ptr<Figure> RectangleFabric::createFigure() {
    Dot uLeft, lRight;
    std::string creationName;
    std::shared_ptr<Figure> figure = nullptr;
    std::string prompt = "Enter data for rectangle to create object - (Name LeftX UpperY RightX LowerY): ";
    InputValidator::getInput<std::string, double, double, double, double>(prompt, &creationName, &uLeft.x, &uLeft.y, &lRight.x, &lRight.y);
    if (InputValidator::isError == false)
        try {
            figure = std::make_shared<Rectangle>(creationName, uLeft, lRight);
        } catch (std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    return figure;
}

std::shared_ptr<Figure> TriangleFabric::createFigure() {
    Dot c1, c2, c3;
    std::string creationName;
    std::shared_ptr<Figure> figure = nullptr;
    std::string prompt = "Enter data for triangle to create object - (Name 3XY for each coord., split by space): ";
    InputValidator::getInput<std::string, double, double, double, double, double, double>(prompt, &creationName, &c1.x, &c1.y, &c2.x, &c2.y, &c3.x, &c3.y);
    if (InputValidator::isError == false)
        try {
            figure = std::make_shared<Triangle>(creationName, c1, c2, c3);
        } catch (std::invalid_argument& e) {
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
