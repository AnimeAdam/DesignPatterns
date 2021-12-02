//A really basic pattern to be honest just when an object is null here's what it does.
#include <iostream>

class animal
{
public:
    virtual void make_sound() const = 0;
};

class dog : public animal
{
    virtual void make_sound() const override
    {
        std::cout << "woof!" << std::endl;
    }
};

class null_animal : public animal
{
    virtual void make_sound() const override { }
};

int main()
{
    //IF dog is a Null = null_animal.
    return 0;
}