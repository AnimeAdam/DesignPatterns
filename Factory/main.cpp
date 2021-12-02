//The factory pattern is about creating a factory class with a load of if statements
//that spit out a shared_pointer to a class that is inherting a superclass.

#include <iostream>
#include <memory>
#include "AnimalFactory.h"

using namespace std;

int main()
{
	//create a shared pointer to the superclass
	std::shared_ptr<Animal> Beary = NULL;
	//assign the correct class to it with the factory
	Beary = AnimalFactory::getAnimal("bear");
	cout << Beary->getname() << endl;

	std::shared_ptr<Animal> Caty = NULL;
	Caty = AnimalFactory::getAnimal("cat");
	//You can also clone them with the same basic princpal as the factory
	std::shared_ptr<Animal> Caty2 = Caty->clone();
	cout << Caty2->getname() << endl;

	cout << "Hello World!";

	return 0;
}
