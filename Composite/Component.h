#pragma once
#include <iostream>
#include <vector>

// 2. Create an "interface" (lowest common denominator)
class Component
{
public:
    virtual void traverse() = 0;
};