#pragma once
#include <string>
#include <iostream>
#include "Flying.h"

using namespace std;

class Animal
{
protected:
    string name;
    double height;
    int weight;
    Flying* flyingType;

public:
    Animal();

    string getName() { return name; }
    double getHeight() { return height; }
    int getWeight() { return weight; }
    Flying* getFlyingType() { return flyingType; }

    void setName(string newName) { name = newName; }
    void setHeight(double newHeight) { height = newHeight; }
    void setWeight(int newWeight);
    void setFlyingType(Flying* ft) {this->flyingType = ft; } 
};