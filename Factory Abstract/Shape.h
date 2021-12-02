#pragma once
#include <iostream>

using namespace std;

class Shape {
public:
    Shape() {
        id_ = total_++;
    }
    virtual void draw() = 0;
protected:
    int id_;
    static int total_;
};
int Shape::total_ = 0;