#ifndef FIGURESMANAGER_H
#define FIGURESMANAGER_H

#include <vector>

#include "figures.h"
#include "fabric.h"

enum figTypes {
    CIRCLE = 1,
    RECTANGLE,
    TRIANGLE
};

class figuresManager {
    public:
    figuresManager(): cFabric(), rFabric(), tFabric() {};
    void addCircle();
    void addRectangle();
    void addTriangle();
    void printFigures() const;
    void printFiguresPerimeters() const;
    void printPerimetersSum() const;
    void sortFigures();
    void deleteFigureByNumber();
    void deleteFiguresByPerimeter();
    void addFigure();
    private:
    std::vector<std::shared_ptr<Figure>> figures;
    CircleFabric cFabric;
    RectangleFabric rFabric;
    TriangleFabric tFabric;
};



#endif //FIGURESMANAGER_H
