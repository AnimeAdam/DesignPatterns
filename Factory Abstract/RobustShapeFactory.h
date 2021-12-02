#pragma once
#include "Factory.h"
#include "Ellipse.h"
#include "Rectangle.h"

class RobustShapeFactory : public Factory {
public:
    Shape* createCurvedInstance() {
        return new Ellipse;
    }
    Shape* createStraightInstance() {
        return new Rectangle;
    }
};