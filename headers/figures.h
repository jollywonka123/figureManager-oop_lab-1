#ifndef FIGURES_H
#define FIGURES_H

#include <string>
#include <array>
#define EPS 1e-6
#include "dot.h"

class Figure {
public:
    explicit Figure(std::string str): name(std::move(str)) {}
    virtual double getPerimeter() const = 0;
    virtual void printFigure() const = 0;
    virtual void printFigurePerimeter() const = 0;
    virtual ~Figure() = default;
protected:
    const std::string name;
};

class Circle: public Figure {
public:
    Circle(std::string str, const Dot& centreCoord, double rad);
    double getPerimeter() const override;
    void printFigure() const override;
    void printFigurePerimeter() const override;
    ~Circle() override = default;
private:
    Dot centre;
    double radius;

};

class Rectangle: public Figure {
public:
    Rectangle(std::string str, const Dot& uLeft, const Dot& lRight);
    double getPerimeter() const override;
    void printFigure() const override;
    void printFigurePerimeter() const override;
    ~Rectangle() override = default;
private:
    Dot upperLeftCoordinate{};
    Dot lowerRightCoordinate{};
};

class Triangle: public Figure {
    public:
    Triangle(std::string str, const Dot& c1, const Dot& c2, const Dot& c3);
    double getPerimeter() const override;
    void printFigure() const override;
    void printFigurePerimeter() const override;
    ~Triangle() override = default;
    private:
    Dot coordinate1{};
    Dot coordinate2{};
    Dot coordinate3{};
};

#endif //FIGURES_H
