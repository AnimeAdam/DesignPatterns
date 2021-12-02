#pragma once

#include "Decorator.h"

class BorderDecorator : public Decorator
{
public:
    // 6. Optional embellishment
    BorderDecorator(Widget* w) : Decorator(w) {}

    /*virtual*/
    void draw()
    {
        // 7. Delegate to base class and add extra stuff
        Decorator::draw();
        std::cout << "   BorderDecorator" << '\n';
    }
};