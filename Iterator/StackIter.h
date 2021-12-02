#pragma once
#include "Stack.h"

class Stack;

class StackIter
{
    // 1. Design an "iterator" class
    const Stack* stk;
    int index;
public:
    StackIter(const Stack* s);
    void first();
    void next();
    bool isDone();
    int currentItem();
};

