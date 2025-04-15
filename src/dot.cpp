#include "../headers/dot.h"
#include "../headers/inputValidator.h"

void Dot::setX(const std::string& name) {
    std::string prompt = "Enter x for " + name + ": ";
    InputValidator::getInput(prompt, &x);
    if (InputValidator::isError == true) {
        std::string msg = "Cant set x for " + name;
        throw std::logic_error(msg);
    }
}

void Dot::setY(const std::string& name) {
    std::string prompt = "Enter y for " + name + ": ";
    InputValidator::getInput(prompt, &y);
    if (InputValidator::isError == true) {
        std::string msg = "Cant set y for " + name;
        throw std::logic_error(msg);
    }
}

Dot::Dot(const std::string& name) {
    setX(name);
    setY(name);
}

double Dot::getX() const {
    return x;
}

double Dot::getY() const {
    return y;
}