#include "../headers/fabric.h"
#include "../headers/inputValidator.h"
#include "string"

std::shared_ptr<Figure> CircleFabric::createFigure() {
    double x, y, rad;
    std::shared_ptr<Figure> figure = nullptr;
    std::string creationName;
    std::string prompt = "Enter data for circle to create object - (Name X Y Radius): ";
    InputValidator::getInput<std::string, double, double, double>(prompt, &creationName, &x, &y, &rad);
    if (InputValidator::isError == false)
        try {
            figure = std::make_shared<Circle>(creationName, x, y, rad);
        } catch (std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    return figure;
}

std::shared_ptr<Figure> RectangleFabric::createFigure() {
    double xLeft, yUpper, xRight, yLower;
    std::string creationName;
    std::shared_ptr<Figure> figure = nullptr;
    std::string prompt = "Enter data for rectangle to create object - (Name LeftX UpperY RightX LowerY): ";
    InputValidator::getInput<std::string, double, double, double, double>(prompt, &creationName, &xLeft, &yUpper, &xRight, &yLower);
    if (InputValidator::isError == false)
        try {
            figure = std::make_shared<Rectangle>(creationName, xLeft, yUpper, xRight, yLower);
        } catch (std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    return figure;
}

std::shared_ptr<Figure> TriangleFabric::createFigure() {
    double x1, y1, x2, y2, x3, y3;
    std::string creationName;
    std::shared_ptr<Figure> figure = nullptr;
    std::string prompt = "Enter data for triangle to create object - (Name 3XY for each coord., split by space): ";
    InputValidator::getInput<std::string, double, double, double, double, double, double>(prompt, &creationName, &x1, &y1, &x2, &y2, &x3, &y3);
    if (InputValidator::isError == false)
        try {
            figure = std::make_shared<Triangle>(creationName, x1, x2, x3, y1, y2, y3);
        } catch (std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    return figure;
}