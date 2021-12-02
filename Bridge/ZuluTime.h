#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Time.h"
#include "ZuluTimeImp.h"

using namespace std;

class ZuluTime : public Time {
public:
    ZuluTime(int hr, int min, int zone) {
        imp_ = new ZuluTimeImp(hr, min, zone);
    }
};