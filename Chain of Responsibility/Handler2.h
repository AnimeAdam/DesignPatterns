#pragma once
#include "Base.h"

class Handler2 : public Base
{
public:
    /*virtual*/void handle(int i)
    {
        if (rand() % 3)
        {
            cout << "H2 passed " << i << "  ";
            Base::handle(i);
        }
        else
            cout << "H2 handled " << i << "  ";
    }
};