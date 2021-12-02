#pragma once
#include <string>

using namespace std;

//Interface superclass
class Flying
{
public:
    virtual string fly() = 0;
};

//A varient of this interface superclass
class Flys : public Flying
{
public:
    string fly() { return "Flying High"; }
};

//A varient of this interface superclass
class CantFly : public Flying
{
public:
    string fly() { return "I can't fly"; }
};