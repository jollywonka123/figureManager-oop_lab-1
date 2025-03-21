#ifndef FABRIC_H
#define FABRIC_H

#include <memory>
#include "figures.h"

class Fabric {
public:
    virtual std::shared_ptr<Figure> createFigure() = 0;
    virtual ~Fabric() = default;
};

class CircleFabric : public Fabric {
    public:
    std::shared_ptr<Figure> createFigure() override;
    ~CircleFabric() override = default;
};

class RectangleFabric : public Fabric {
public:
    std::shared_ptr<Figure> createFigure() override;
    ~RectangleFabric() override = default;
};

class TriangleFabric : public Fabric {
public:
    std::shared_ptr<Figure> createFigure() override;
    ~TriangleFabric() override = default;
};

#endif //FABRIC_H
