#include "AnalogClock.h"

void AnalogClock::Update(Subject& theChangedSubject)
{
    //error check for if current subject class the same one this class is pointing to
    if (&theChangedSubject == &subject) {
        Draw();
    }
}

void AnalogClock::Draw()
{
    int hour = subject.GetHour();
    int minute = subject.GetMinute();
    int second = subject.GetSecond();

    std::cout << "Analog time is " << hour << ":"
        << minute << ":"
        << second << std::endl;
}
