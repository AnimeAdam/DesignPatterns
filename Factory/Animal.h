#pragma once
#include <string>
#include <memory>


class Animal {
public:
    virtual std::shared_ptr<Animal> clone() const = 0;

    virtual std::string  getname() const = 0;
};
