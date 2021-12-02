#pragma once
#include "Base.h"

class Handler1 : public Base
{
public:
    /*virtual*/void handle(int i)
    {
        if (rand() % 3)
        {
            // 3. Don't handle requests 3 times out of 4
            cout << "H1 passed " << i << "  ";
            Base::handle(i); // 3. Delegate to the base class
        }
        else
            cout << "H1 handled " << i << "  ";
    }
};