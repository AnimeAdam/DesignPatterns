#pragma once
#include <iostream>
#include "Observer.h"
#include "ClockTimer.h"

class AnalogClock : public Observer
{
public:
    //explicit means to specify the constructor is explicit and cannot be used for implicit conversion or copy-initialisation.
    //ALSO this is a fancy way of using an initializer lists.
    //Class() : privateVariable(assignValue) {function body}, privateVariable(assignValue) {function body}
    explicit AnalogClock(ClockTimer& s) : subject(s) { subject.Attach(*this); }
    ~AnalogClock() { subject.Detach(*this); }

    //override specifier ensures that the function is virtual and is overriding 
    //a virtual function from a base class. 
    void Update(Subject& theChangedSubject) override;
    void Draw();

private:
    ClockTimer& subject;
};