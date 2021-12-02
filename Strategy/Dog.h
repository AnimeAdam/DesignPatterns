#pragma once
#include "Animal.h"

class Dog : public Animal
{
private:
	string dogCollar;

public:
	Dog();
	
	void DigHole();

};