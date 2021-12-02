#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class TimeImp {
public:
    TimeImp(int hr, int min) {
        hr_ = hr;
        min_ = min;
    }
    virtual void tell() {
        cout << "time is " << setw(2) << setfill(48) << hr_ << min_ << endl;
    }
protected:
    int hr_, min_;
};