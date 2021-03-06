#pragma once

#include "Subject.h"

class Subject;

class Observer
{
public:
    //the = default means, Forcing a destructor to be generated by the compiler.
    virtual ~Observer() = default;
    virtual void Update(Subject&) = 0;
};