#pragma once

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Base
{
    Base* next; // 1. "next" pointer in the base class
public:
    Base()
    {
        next = 0;
    }
    void setNext(Base* n)
    {
        next = n;
    }
    void add(Base* n)
    {
        if (next)
            next->add(n);
        else
            next = n;
    }
    // 2. The "chain" method in the base class always delegates to the next obj
    virtual void handle(int i)
    {
        next->handle(i);
    }
};