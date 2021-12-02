//The builder pattern is for creating objects from other objects 

#include "Builder_Automobile.h"

int main() {

    CarBattery carBat;

    //the first function needs to be accessed in the builder class because
    //each function returns a pointer to the same builder class
    //the last one must be the function that builds object.
    Automobile automobile = Automobile::Builder().numberOfTires(4) 
        ->bodyType("coupe")
        ->engineType("V8")
        ->fuelTankSizeInGallons(16)
        ->airConditioned(true)
        ->odometerMiles(20000)
        ->carBattery(carBat)->build();

    std::cout << automobile.getNumberOfTires();

    return 0;
}

//Alternative way of making a builder pattern if you don't want to use pointers for whatever reason.
//#include <vector>
//
//class foo
//{
//public:
//    class builder;
//    foo(int prop1, bool prop2, bool prop3, std::vector<int> prop4)
//        : prop1{ prop1 }, prop2{ prop2 }, prop3{ prop3 }, prop4{ prop4 }
//    { }
//    int prop1;
//    bool prop2;
//    bool prop3;
//    std::vector<int> prop4;
//};
//class foo::builder
//{
//public:
//    builder& set_prop1(int value) { prop1 = value; return *this; };
//    builder& set_prop2(bool value) { prop2 = value; return *this; };
//    builder& set_prop3(bool value) { prop3 = value; return *this; };
//    builder& set_prop4(std::vector<int> value) { prop4 = value; return *this; };
//    foo build() const
//    {
//        return foo{ prop1, prop2, prop3, prop4 };
//    }
//private:
//    int prop1 = 0;
//    bool prop2 = false;
//    bool prop3 = false;
//    std::vector<int> prop4 = {};
//};
//int main()
//{
//    foo f = foo::builder{}.set_prop1(5)
//        .set_prop3(true)
//        .build();
//}