#pragma once
#include "Base.h"

class Handler3 : public Base
{
public:
    /*virtual*/void handle(int i)
    {
        if (rand() % 3)
        {
            cout << "H3 passed " << i << "  ";
            Base::handle(i);
        }
        else
            cout << "H3 handled " << i << "  ";
    }
};
