#pragma once

#include "Decorator.h"

class ScrollDecorator : public Decorator
{
public:
    // 6. Optional embellishment
    ScrollDecorator(Widget* w) : Decorator(w) {}

    /*virtual*/
    void draw()
    {
        // 7. Delegate to base class and add extra stuff
        Decorator::draw();
        std::cout << "   ScrollDecorator" << '\n';
    }
};