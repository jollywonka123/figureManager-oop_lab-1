#ifndef FIGURES_H
#define FIGURES_H

#include <string>
#include <utility>
#include <array>
#include <stdexcept>
#define EPS 0.0000001


class FigureContainer {

};

class Figure {
public:
    const std::string name;
    explicit Figure(std::string str): name(std::move(str)) {};
    virtual double getPerimeter() const = 0;
    virtual void printFigure() const = 0;
    virtual void printFigurePerimeter() const = 0;
    virtual ~Figure() = default;
};

class Circle: public Figure {
public:
    Circle(std::string str, double x, double y, double rad);
    double getPerimeter() const override;
    void printFigure() const override;
    void printFigurePerimeter() const override;
    ~Circle() override = default;
private:
    std::array<double, 2> centerCoordinate{};
    double radius;

};

class Rectangle: public Figure {
public:
    Rectangle(std::string str, double xLeft, double yUpper, double xRight, double yLower);
    double getPerimeter() const override;
    void printFigure() const override;
    void printFigurePerimeter() const override;
    ~Rectangle() override = default;
private:
    std::array<double, 2> upperLeftCoordinate{};
    std::array<double, 2> lowerRightCoordinate{};
};

class Triangle: public Figure {
    public:
    Triangle(std::string str, double x1, double y1, double x2, double y2, double x3, double y3);
    double getPerimeter() const override;
    void printFigure() const override;
    void printFigurePerimeter() const override;
    ~Triangle() override = default;
    private:
    std::array<double, 2> coordinate1{};
    std::array<double, 2> coordinate2{};
    std::array<double, 2> coordinate3{};
};

#endif //FIGURES_H
