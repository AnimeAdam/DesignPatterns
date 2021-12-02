#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "TimeImp.h"

using namespace std;

class Time {
public:
    Time() {}
    Time(int hr, int min) {
        imp_ = new TimeImp(hr, min);
    }
    virtual void tell() {
        imp_->tell();
    }
protected:
    TimeImp* imp_;
};