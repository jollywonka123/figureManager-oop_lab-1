#include "../headers/figures.h"
#include <cmath>
#include <iostream>
#include <iomanip>

Circle::Circle(std::string str, double x, double y, double rad):
    Figure(std::move(str)), centerCoordinate{x, y} {
    if (rad <= 0)
        throw std::invalid_argument("Radius must be positive");
    else this->radius = rad;
}

double Circle::getPerimeter() const {
    return 2 * M_PI * radius;
}

void Circle::printFigure() const {
    std::cout << "Circle: " << this->name << " | centre coordinate: " << this->centerCoordinate[0] << ", " << this->centerCoordinate[1] << " | radius: " << this->radius <<std::endl;
}

void Circle::printFigurePerimeter() const {
    std::cout << std::fixed << std::setprecision(3) << "Circle perimeter: " << this->getPerimeter() << std::endl;
}


Rectangle::Rectangle(std::string str, double xLeft, double yUpper, double xRight, double yLower):
    Figure(std::move(str)) {
    if ((xRight < xLeft) && (yUpper < yLower)) {
        throw std::invalid_argument("Invalid coordinates");
    }
    else {
        upperLeftCoordinate = {xLeft, yUpper};
        lowerRightCoordinate = {xRight, yLower};
    }
}

double Rectangle::getPerimeter() const {
    return 2 * ((upperLeftCoordinate[1] - lowerRightCoordinate[1])+(lowerRightCoordinate[0] - upperLeftCoordinate[0]));
}

void Rectangle::printFigure() const {
    std::cout << "Rectangle: " << this->name << " | Upper Left coordinate: " << this->upperLeftCoordinate[0] << ", " << this->upperLeftCoordinate[1] << " | Lower Right coordinate: " << this->lowerRightCoordinate[0] << ", " << this->lowerRightCoordinate[1] <<std::endl;
}

void Rectangle::printFigurePerimeter() const {
    std::cout << std::fixed << std::setprecision(3) << "Rectangle perimeter: " << this->getPerimeter() << std::endl;
}

Triangle::Triangle(std::string str, double x1, double y1, double x2, double y2, double x3, double y3):
    Figure(std::move(str)) {
    if ((fabs(x1-x2) < EPS && fabs(y1-y2) < EPS)||(fabs(x2-x3) < EPS && fabs(y2-y3) < EPS)||(fabs(x1-x3) < EPS && fabs(y1-y3) < EPS))
        throw std::invalid_argument("Invalid coordinates");
    else {
        coordinate1 = {x1, y1};
        coordinate2 = {x2, y2};
        coordinate3 = {x3, y3};
    }
}

double Triangle::getPerimeter() const {
    double length1 = sqrt(pow(coordinate2[0] - coordinate1[0], 2) + pow(coordinate2[1] - coordinate1[1], 2));
    double length2 = sqrt(pow(coordinate3[0] - coordinate2[0], 2) + pow(coordinate3[1] - coordinate2[1], 2));
    double length3 = sqrt(pow(coordinate3[0] - coordinate1[0], 2) + pow(coordinate3[1] - coordinate1[1], 2));
    return length1 + length2 + length3;
}

void Triangle::printFigure() const {
    std::cout << "Triangle: " << this->name << " | Coordinates of vertexes: " << this->coordinate1[0] << ", " << this->coordinate1[1] << "; " << this->coordinate2[0] << ", " << this->coordinate2[1] << "; " << this->coordinate3[0] << ", " << this->coordinate3[1] <<std::endl;
}

void Triangle::printFigurePerimeter() const {
    std::cout << std::fixed << std::setprecision(3) << "Triangle perimeter: " << this->getPerimeter() << std::endl;
}