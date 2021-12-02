#include "ClockTimer.h"

void ClockTimer::SetTime(int hour, int minute, int second)
{
    this->hour = hour;
    this->minute = minute;
    this->second = second;

    Notify();
}
