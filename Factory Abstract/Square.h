#pragma once
#include "Shape.h"

class Square : public Shape {
public:
    void draw() {
        cout << "square " << id_ << ": draw" << endl;
    }
};