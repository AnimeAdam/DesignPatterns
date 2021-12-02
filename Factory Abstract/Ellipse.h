#pragma once
#include "Shape.h"


class Ellipse : public Shape {
public:
    void draw() {
        cout << "ellipse " << id_ << ": draw" << endl;
    }
};