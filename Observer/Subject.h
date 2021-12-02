#pragma once
// This interface handles adding, deleting and updating all observers

#include <vector>
#include "Observer.h"

class Observer;

class Subject
{
private:
    //vector of pointers to instants of observers.
    std::vector<Observer*> observers;

public:
    //the = default means, Forcing a destructor to be generated by the compiler.
    virtual ~Subject() = default;
    //Puts the observers on the stack
    void Attach(Observer& o) { observers.push_back(&o); } 
    //Removes the observer from the stack
    void Detach(Observer& o) { observers.erase(std::remove(observers.begin(), observers.end(), &o)); } 
    //Goes through the list of observers and updates them.
    void Notify() 
    {
        for (auto* o : observers) {
            o->Update(*this);
        }
    }
};