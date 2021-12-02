//Strategy pattern is creating an interface for a superclass
//that can be added to different classes with different needs

#include <iostream>
#include "Dog.h"

using namespace std;

int main()
{
	Dog dg; //create an instance of class inherting a superclass
	dg.DigHole(); //calling function in the Dog class
	cout << "\n" << dg.getName() << "\n"; //call function that is shared in both super and normal class
	cout << dg.getFlyingType()->fly() << "\n"; //The Strategy pattern right here, look in Flying.h and Dog.cpp
	cout << "Hello World!!!";


	return 0;
}
