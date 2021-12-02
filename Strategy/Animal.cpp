#include "Animal.h"

Animal::Animal()
{
}

void Animal::setWeight(int newWeight)
{
    if (newWeight > 0) {
        weight = newWeight;
    }
    else {
        cout << "Weight must be bigger than 0";
    }
}
