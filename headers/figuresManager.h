#ifndef FIGURESMANAGER_H
#define FIGURESMANAGER_H

#include <vector>
#include <memory>
#include "figures.h"
#include "fabric.h"
#include <map>
#include <utility>
#include <string>
#include <functional>

enum figTypes {
    CIRCLE = 1,
    RECTANGLE,
    TRIANGLE
};

using namespace std;

class FiguresManager {
public:
    FiguresManager();
    using func = function<void()>;
    using methodPair = pair<string, func>;
    map<int, methodPair> actionMap;
private:
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
    vector<shared_ptr<Figure>> figures;
    unique_ptr<FabricsFactory> fabricFactory;
    map<int, methodPair> figureCreationMap;
};



#endif //FIGURESMANAGER_H
