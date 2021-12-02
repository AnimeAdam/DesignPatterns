#pragma once
#include "Subject.h"

class ClockTimer : public Subject
{
public:
    void SetTime(int hour, int minute, int second);

    int GetHour() const { return hour; }
    int GetMinute() const { return minute; }
    int GetSecond() const { return second; }

private:
    int hour;
    int minute;
    int second;
};
