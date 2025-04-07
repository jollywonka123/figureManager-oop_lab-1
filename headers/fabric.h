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

class AbstractFabricsFactory {
    public:
    virtual std::shared_ptr<CircleFabric> createCircleFabric() = 0;
    virtual std::shared_ptr<RectangleFabric> createRectangleFabric() = 0;
    virtual std::shared_ptr<TriangleFabric> createTriangleFabric() = 0;
    virtual ~AbstractFabricsFactory() = default;
};

class FabricsFactory : public AbstractFabricsFactory {
    public:
    std::shared_ptr<CircleFabric> createCircleFabric() override;
    std::shared_ptr<RectangleFabric> createRectangleFabric() override;
    std::shared_ptr<TriangleFabric> createTriangleFabric() override;
    ~FabricsFactory() override = default;
};

#endif //FABRIC_H
