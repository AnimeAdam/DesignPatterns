//The Bridge pattern uses abstract classes for the interfaces which is added
//to it's implementation as an object to make it more flexible abstractions
//using aggregation/composition rather than inheritance/generalization.

//THIS EXAMPLE MAKES HEAVY USE OF THE iomanip LIBRARY
#include <iostream>
#include <iomanip>
#include <string>
#include "Time.h"
#include "CivilianTime.h"
#include "ZuluTime.h"

using namespace std;


int main() {
    Time* times[3];
    times[0] = new Time(14, 30);
    times[1] = new CivilianTime(2, 30, 1);
    times[2] = new ZuluTime(14, 30, 6);
    for (int i = 0; i < 3; i++)
        times[i]->tell();
}