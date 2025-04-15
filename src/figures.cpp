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
    std::cout << "Circle: " << this->name << " | centre coordinate: " << this->centre.getX() << ", " << this->centre.getY() << " | radius: " << this->radius <<std::endl;
}

void Circle::printFigurePerimeter() const {
    std::cout << std::fixed << std::setprecision(3) << "Circle perimeter: " << this->getPerimeter() << std::endl;
}


Rectangle::Rectangle(std::string str, const Dot& uLeft, const Dot& lRight):
    Figure(std::move(str)), upperLeftCoordinate(uLeft), lowerRightCoordinate(lRight) {
    if ((uLeft.getX() > lRight.getX()) && (uLeft.getY() < lRight.getY())) {
        throw std::invalid_argument("Invalid coordinates");
    }
}

double Rectangle::getPerimeter() const {
    return 2 * ((upperLeftCoordinate.getY() - lowerRightCoordinate.getY())+(lowerRightCoordinate.getX() - upperLeftCoordinate.getX()));
}

void Rectangle::printFigure() const {
    std::cout << "Rectangle: " << this->name << " | Upper Left coordinate: " << this->upperLeftCoordinate.getX() << ", " << this->upperLeftCoordinate.getY() << " | Lower Right coordinate: " << this->lowerRightCoordinate.getX() << ", " << this->lowerRightCoordinate.getY() <<std::endl;
}

void Rectangle::printFigurePerimeter() const {
    std::cout << std::fixed << std::setprecision(3) << "Rectangle perimeter: " << this->getPerimeter() << std::endl;
}

Triangle::Triangle(std::string str, const Dot& c1, const Dot& c2, const Dot& c3):
    Figure(std::move(str)), coordinate1(c1), coordinate2(c2), coordinate3(c3) {
    if ((fabs(c1.getX() - c2.getX()) < EPS && fabs(c1.getY() - c2.getY()) < EPS)||(fabs(c2.getX() - c3.getX()) < EPS && fabs(c2.getY() - c3.getY()) < EPS)||(fabs(c1.getX() - c3.getX()) < EPS && fabs(c1.getY() - c3.getY()) < EPS))
        throw std::invalid_argument("Invalid coordinates");
}

double Triangle::calculateLength(const Dot &coord1, const Dot &coord2) {
    return sqrt(pow(coord1.getX() - coord2.getX(), 2) + pow(coord1.getY() - coord2.getY(), 2));
}

double Triangle::getPerimeter() const {
    double length1 = calculateLength(coordinate1, coordinate2);
    double length2 = calculateLength(coordinate2, coordinate3);
    double length3 = calculateLength(coordinate3, coordinate1);
    return length1 + length2 + length3;
}

void Triangle::printFigure() const {
    std::cout << "Triangle: " << this->name << " | Coordinates of vertexes: " << this->coordinate1.getX() << ", " << this->coordinate1.getY() << "; " << this->coordinate2.getX() << ", " << this->coordinate2.getY() << "; " << this->coordinate3.getX() << ", " << this->coordinate3.getY() <<std::endl;
}

void Triangle::printFigurePerimeter() const {
    std::cout << std::fixed << std::setprecision(3) << "Triangle perimeter: " << this->getPerimeter() << std::endl;
}
