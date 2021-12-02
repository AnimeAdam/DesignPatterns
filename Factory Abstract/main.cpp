//The Absract Factory is like a regular pattern but allows for more flexiblity
//So pretty much give an interface for the objects that are produced by the factory

#pragma once
#include "Factory.h"
#include "SimpleShapeFactory.h"
#include "RobustShapeFactory.h"

int main() {
//SIMPLE
    Factory* factory = new SimpleShapeFactory;
//ROBUST
    //Factory* factory = new RobustShapeFactory;

    Shape* shapes[3];

    shapes[0] = factory->createCurvedInstance();   // shapes[0] = new Ellipse;
    shapes[1] = factory->createStraightInstance(); // shapes[1] = new Rectangle;
    shapes[2] = factory->createCurvedInstance();   // shapes[2] = new Ellipse;

    for (int i = 0; i < 3; i++) {
        shapes[i]->draw();
    }
}