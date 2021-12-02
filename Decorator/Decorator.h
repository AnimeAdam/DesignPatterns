#pragma once

#include "Widget.h"

// 2. 2nd level base class
class Decorator : public Widget  // 4. "is a" relationship
{
    Widget* wid; // 4. "has a" relationship
public:
    Decorator(Widget* w)
    {
        wid = w;
    }

    /*virtual*/
    void draw()
    {
        wid->draw(); // 5. Delegation
    }
};