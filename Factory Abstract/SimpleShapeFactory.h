#pragma once
#include "Factory.h"
#include "Circle.h"
#include "Square.h"


class SimpleShapeFactory : public Factory {
public:
    Shape* createCurvedInstance() {
        return new Circle;
    }
    Shape* createStraightInstance() {
        return new Square;
    }
};