#pragma once
#include "Shape.h"


class Rectangle : public Shape {
public:
    void draw() {
        cout << "rectangle " << id_ << ": draw" << endl;
    }
};