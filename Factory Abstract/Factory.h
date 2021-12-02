#pragma once
#include "Shape.h"

class Factory {
public:
    virtual Shape* createCurvedInstance() = 0;
    virtual Shape* createStraightInstance() = 0;
};