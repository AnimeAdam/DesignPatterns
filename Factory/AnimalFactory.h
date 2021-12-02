#pragma once
#include "Animal.h"
#include "Cat.h"
#include "Bear.h"

class AnimalFactory {
public:
    static std::shared_ptr<Animal> getAnimal(const std::string& name)
    {
        if (name == "bear")
            return std::make_shared<Bear>();
        if (name == "cat")
            return std::make_shared<Cat>();

        return nullptr;
    }


};