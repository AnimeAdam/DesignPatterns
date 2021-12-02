#pragma once
#include "Component.h"

class Leaf : public Component
{
    // 1. Scalar class   3. "isa" relationship
    int value;
public:
    Leaf(int val)
    {
        value = val;
    }
    void traverse()
    {
        std::cout << value << ' ';
    }
};