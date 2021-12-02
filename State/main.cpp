//The State Pattern allow an object to alter its behavior when its internal state changes. 


//The current example needs to be executed in this order for it to work.
#include <iostream>

using namespace std;

class Machine
{
    class State* current;
public:
    Machine();
    void setCurrent(State* s)
    {
        current = s;
    }
    void on();
    void off();
};

class State
{
public:
    virtual void on(Machine* m)
    {
        cout << "   already ON\n";
    }
    virtual void off(Machine* m)
    {
        cout << "   already OFF\n";
    }
};

//The functions below need to be defined afterwards because they use
//the State class which needs to be defined beforehand.

void Machine::on()
{
    current->on(this);
}

void Machine::off()
{
    current->off(this);
}

class ON : public State
{
public:
    ON()
    {
        cout << "   ON-ctor ";
    };
    ~ON()
    {
        cout << "   dtor-ON\n";
    };
    void off(Machine* m);
};

class OFF : public State
{
public:
    OFF()
    {
        cout << "   OFF-ctor ";
    };
    ~OFF()
    {
        cout << "   dtor-OFF\n";
    };
    void on(Machine* m)
    {
        cout << "   going from OFF to ON";
        m->setCurrent(new ON());
        delete this;
    }
};

void ON::off(Machine* m)
{
    cout << "   going from ON to OFF";
    m->setCurrent(new OFF());
    delete this;
}

Machine::Machine()
{
    current = new OFF();
    cout << '\n';
}

int main()
{
    //An array of void pointers to functions in the Machine class/scope
    void(Machine:: *ptrs[])() =
    {
      &Machine::off, &Machine::on
    };
    Machine fsm;
    int num;
    while (1)
    {
        cout << "Enter 0/1: ";
        cin >> num;
        (fsm.*ptrs[num])(); //How to access the functions in the array
    }
}