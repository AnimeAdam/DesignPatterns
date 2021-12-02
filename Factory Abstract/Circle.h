#pragma once
#include "Shape.h"

class Circle : public Shape {
public:
    void draw() {
        cout << "circle " << id_ << ": draw" << endl;
    }
};