#include "Dog.h"

Dog::Dog()
{
	setName("Barkie");
	flyingType = new CantFly();
}

void Dog::DigHole()
{
	cout << ("Dug a hole");
}
