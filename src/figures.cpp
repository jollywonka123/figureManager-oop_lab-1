#include "../headers/figures.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <utility>

Circle::Circle(std::string str, const Dot& centreCoord, double rad):
    Figure(std::move(str)), centre(centreCoord) {
    if (rad <= 0)
        throw std::invalid_argument("Radius must be positive");
    this->radius = rad;
}

double Circle::getPerimeter() const {
    return 2 * M_PI * radius;
}

void Circle::printFigure() const {
    std::cout << "Circle: " << this->name << " | centre coordinate: " << this->centre.x << ", " << this->centre.y << " | radius: " << this->radius <<std::endl;
}

void Circle::printFigurePerimeter() const {
    std::cout << std::fixed << std::setprecision(3) << "Circle perimeter: " << this->getPerimeter() << std::endl;
}


Rectangle::Rectangle(std::string str, const Dot& uLeft, const Dot& lRight):
    Figure(std::move(str)) {
    if ((uLeft.x > lRight.x) && (uLeft.y < lRight.y)) {
        throw std::invalid_argument("Invalid coordinates");
    }
    upperLeftCoordinate = uLeft;
    lowerRightCoordinate = lRight;
}

double Rectangle::getPerimeter() const {
    return 2 * ((upperLeftCoordinate.y - lowerRightCoordinate.y)+(lowerRightCoordinate.x - upperLeftCoordinate.x));
}

void Rectangle::printFigure() const {
    std::cout << "Rectangle: " << this->name << " | Upper Left coordinate: " << this->upperLeftCoordinate.x << ", " << this->upperLeftCoordinate.y << " | Lower Right coordinate: " << this->lowerRightCoordinate.x << ", " << this->lowerRightCoordinate.y <<std::endl;
}

void Rectangle::printFigurePerimeter() const {
    std::cout << std::fixed << std::setprecision(3) << "Rectangle perimeter: " << this->getPerimeter() << std::endl;
}

Triangle::Triangle(std::string str, const Dot& c1, const Dot& c2, const Dot& c3):
    Figure(std::move(str)) {
    if ((fabs(c1.x - c2.x) < EPS && fabs(c1.y - c2.y) < EPS)||(fabs(c2.x - c3.x) < EPS && fabs(c2.y - c3.y) < EPS)||(fabs(c1.x - c3.x) < EPS && fabs(c1.y - c3.y) < EPS))
        throw std::invalid_argument("Invalid coordinates");
    else {
        coordinate1 = c1;
        coordinate2 = c2;
        coordinate3 = c3;
    }
}

double Triangle::getPerimeter() const {
    double length1 = sqrt(pow(coordinate2.x - coordinate1.x, 2) + pow(coordinate2.y - coordinate1.y, 2));
    double length2 = sqrt(pow(coordinate3.x - coordinate2.x, 2) + pow(coordinate3.y - coordinate2.y, 2));
    double length3 = sqrt(pow(coordinate3.x - coordinate1.x, 2) + pow(coordinate3.y - coordinate1.y, 2));
    return length1 + length2 + length3;
}

void Triangle::printFigure() const {
    std::cout << "Triangle: " << this->name << " | Coordinates of vertexes: " << this->coordinate1.x << ", " << this->coordinate1.y << "; " << this->coordinate2.x << ", " << this->coordinate2.y << "; " << this->coordinate3.x << ", " << this->coordinate3.y <<std::endl;
}

void Triangle::printFigurePerimeter() const {
    std::cout << std::fixed << std::setprecision(3) << "Triangle perimeter: " << this->getPerimeter() << std::endl;
}
