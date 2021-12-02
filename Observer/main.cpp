//The Observer pattern is a design pattern is when an object(Subject) maintains a list of
//dependencies that automatically notifies the objects (Observers) when there has been a change in the subject.
//Basically something that recieves updates from other classes/objects and keep a record in a vector.

//Note the Subject and Observer require each other so they both need forward declaration.

//It is VERY IMPORTANT to make all the right pointers.

#include <iostream>
#include <vector>
#include "ClockTimer.h"
#include "AnalogClock.h"
#include "DigitalClock.h"

int main()
{
    //The subject that is referenced by the observers(Digital and Analog Clocks in this case).
    ClockTimer timer; //Follow this

    //Sets a pointer to the subject instance for these observers, then
    //tells the pointed subject to attach a pointer to an instant of
    //these observers to a vector class.
    DigitalClock digitalClock(timer);
    AnalogClock analogClock(timer);

    //Where the magic happens, this sets the time in the timer instant, which it then
    //Nofity() tells the other observers to then use the Update function they all share
    //to then set then copy the subject variables into the observer variables.
    timer.SetTime(14, 41, 36);
}