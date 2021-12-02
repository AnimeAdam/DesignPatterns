//The Adapter pattern is used to allow an interface to work with 
//another one or be replaced by it but still keep the old functionality.

#include <iostream>
#include "Rectangle.h"
#include "RectangleAdapter.h" //The key part of this bringing together the old and the new.

using namespace std;


int main()
{
    Rectangle* r = new RectangleAdapter(120, 200, 60, 40); //creating a new object using the new interface with the old one.
    r->draw();
}