#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Time.h"
#include "CivilianTimeImp.h"

using namespace std;

class CivilianTime : public Time {
public:
    CivilianTime(int hr, int min, int pm) {
        imp_ = new CivilianTimeImp(hr, min, pm);
    }
};