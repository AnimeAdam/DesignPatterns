#pragma once
#include "Widget.h"

class TextField : public Widget
{
    // 3. "Core" class & "is a"
    int width, height;
public:
    TextField(int w, int h)
    {
        width = w;
        height = h;
    }

    /*virtual*/
    void draw()
    {
        std::cout << "TextField: " << width << ", " << height << '\n';
    }
};