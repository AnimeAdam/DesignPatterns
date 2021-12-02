#pragma once

#include "Rectangle.h"
#include "LegacyRectangle.h"

// Adapter wrapper
class RectangleAdapter : public Rectangle, private LegacyRectangle
{
public:
    RectangleAdapter(Coordinate x, Coordinate y, Dimension w, Dimension h) :
        LegacyRectangle(x, y, x + w, y + h)
    {
        cout << "RectangleAdapter: create.  (" << x << "," << y <<
            "), width = " << w << ", height = " << h << endl;
    }
    virtual void draw()
    {
        cout << "RectangleAdapter: draw." << endl;
        oldDraw();
    }
};