#include "DigitalClock.h"

void DigitalClock::Update(Subject& theChangedSubject)
{
    //error check for if current subject class the same one this class is pointing to
    if (&theChangedSubject == &subject) {
        Draw();
    }
}

void DigitalClock::Draw()
{
    int hour = subject.GetHour();
    int minute = subject.GetMinute();
    int second = subject.GetSecond();

    std::cout << "Digital time is " << hour << ":"
        << minute << ":"
        << second << std::endl;
}
