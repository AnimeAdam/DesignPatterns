#pragma once

#include "Typedef.h"
#include <iostream>

using namespace std;

// Legacy component
class LegacyRectangle
{
public:
    LegacyRectangle(Coordinate x1, Coordinate y1, Coordinate x2, Coordinate y2)
    {
        x1_ = x1;
        y1_ = y1;
        x2_ = x2;
        y2_ = y2;
        cout << "LegacyRectangle:  create.  (" << x1_ << "," << y1_ << ") => ("
            << x2_ << "," << y2_ << ")" << endl;
    }
    void oldDraw()
    {
        cout << "LegacyRectangle:  oldDraw.  (" << x1_ << "," << y1_ <<
            ") => (" << x2_ << "," << y2_ << ")" << endl;
    }
private:
    Coordinate x1_;
    Coordinate y1_;
    Coordinate x2_;
    Coordinate y2_;
};