//The Dectorator patter is designed to add functionality to objects at run-time. 
//Basically add widgets that are carried across many classes to add things like Textfield or other components that aren't object specific.

#include <iostream>

using namespace std;

#include "Widget.h"
#include "BorderDecorator.h"
#include "ScrollDecorator.h"
#include "Textfield.h"

int main()
{
	Widget* aWidget = new BorderDecorator(new BorderDecorator(new ScrollDecorator
	(new TextField(80, 24))));
	aWidget->draw();

	cout << "Hello World!";

	return 0;
}