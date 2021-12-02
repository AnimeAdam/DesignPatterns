//Proxy pattern is for creating a barrier of security between classes

#include <iostream>

using namespace std;

//The first example both . and -> give different results
class Subject
{
public:
    virtual void execute() = 0;
};

class RealSubject : public Subject
{
    string str;
public:
    RealSubject(string s)
    {
        str = s;
    }
    /*virtual*/void execute()
    {
        cout << str << '\n';
    }
};

class ProxySubject : public Subject
{
    string first, second, third;
    RealSubject* ptr;
public:
    ProxySubject(string s)
    {
        int num = s.find_first_of(' ');
        first = s.substr(0, num);
        s = s.substr(num + 1);
        num = s.find_first_of(' ');
        second = s.substr(0, num);
        s = s.substr(num + 1);
        num = s.find_first_of(' ');
        third = s.substr(0, num);
        s = s.substr(num + 1);
        ptr = new RealSubject(s);
    }
    ~ProxySubject()
    {
        delete ptr;
    }
    RealSubject* operator->()
    {
        cout << first << ' ' << second << ' ';
        return ptr;
    }
    /*virtual*/void execute()
    {
        cout << first << ' ' << third << ' ';
        ptr->execute();
    }
};

int main()
{
    ProxySubject obj(string("the quick brown fox jumped over the dog"));
    obj->execute();
    obj.execute();
}

//The second example is a protection proxy controls access to the original object
/*class Person
{
    string nameString;
    static string list[];
    static int next;
public:
    Person()
    {
        nameString = list[next++];
    }
    string name()
    {
        return nameString;
    }
};
string Person::list[] =
{
  "Tom", "Dick", "Harry", "Bubba"
};
int Person::next = 0;

class PettyCashProtected
{
    int balance;
public:
    PettyCashProtected()
    {
        balance = 500;
    }
    bool withdraw(int amount)
    {
        if (amount > balance)
            return false;
        balance -= amount;
        return true;
    }
    int getBalance()
    {
        return balance;
    }
};

class PettyCash
{
    PettyCashProtected realThing;
public:
    bool withdraw(Person& p, int amount)
    {
        if (p.name() == "Tom" || p.name() == "Harry" || p.name() == "Bubba")
            return realThing.withdraw(amount);
        else
            return false;
    }
    int getBalance()
    {
        return realThing.getBalance();
    }
};

int main()
{
    PettyCash pc;
    Person workers[4];
    for (int i = 0, amount = 100; i < 4; i++, amount += 100)
        if (!pc.withdraw(workers[i], amount))
            cout << "No money for " << workers[i].name() << '\n';
        else
            cout << amount << " dollars for " << workers[i].name() << '\n';
    cout << "Remaining balance is " << pc.getBalance() << '\n';
}*/