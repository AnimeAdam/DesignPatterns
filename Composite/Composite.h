#pragma once
#include "Component.h"

class Composite : public Component
{
    // 1. Vector class   3. "isa" relationship
    std::vector < Component* > children; // 4. "container" coupled to the interface
public:
    // 4. "container" class coupled to the interface
    void add(Component* ele)
    {
        children.push_back(ele);
    }
    void traverse()
    {
        for (int i = 0; i < children.size(); i++)
            // 5. Use polymorphism to delegate to children
            children[i]->traverse();
    }
};