#pragma once
#include "StackIter.h"

class StackIter;

class Stack
{
    int items[10];
    int sp;
public:
    friend class StackIter;
    Stack();
    void push(int in);
    int pop();
    bool isEmpty();
    StackIter* createIterator() const; // 2. Add a createIterator() member
};