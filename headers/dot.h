#ifndef DOT_H
#define DOT_H
#include "string"

class Dot {
private:
    double x{};
    double y{};
public:
    explicit Dot(const std::string& name = "");
    void setX(const std::string& name = "");
    void setY(const std::string& name = "");
    double getX() const;
    double getY() const;
};

#endif //DOT_H
