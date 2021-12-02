//The Key is the Component interface that allows the other classes
//and the composite "containter" class to make list vector list of
//all the other objects in this case Leaf.

#include "Composite.h"
#include "Leaf.h"

int main()
{
    Composite containers[4];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            containers[i].add(new Leaf(i * 3 + j));

    for (int i = 1; i < 4; i++)
        containers[0].add(&(containers[i]));

    for (int i = 0; i < 4; i++)
    {
        containers[i].traverse();
        std::cout << std::endl;
    }
}