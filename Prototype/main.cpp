#include <iostream>

using namespace std;

//The main prototype
class IPrototype {
public:
    //the = default means, Forcing a destructor to be generated by the compiler.
    virtual ~IPrototype() = default;

    auto Clone() const { return std::unique_ptr<IPrototype>{DoClone()}; }
    auto Create() const { return std::unique_ptr<IPrototype>{DoCreate()}; }

private:
    virtual IPrototype* DoClone() const = 0;
    virtual IPrototype* DoCreate() const = 0;
};

class A : public IPrototype {
public:
    auto Clone() const { return std::unique_ptr<A>{DoClone()}; }
    auto Create() const { return std::unique_ptr<A>{DoCreate()}; }
private:
    // Use covariant return type :)
    A* DoClone() const override { return new A(*this); }
    A* DoCreate() const override { return new A; }
};

class B : public IPrototype {
public:
    auto Clone() const { return std::unique_ptr<B>{DoClone()}; }
    auto Create() const { return std::unique_ptr<B>{DoCreate()}; }
private:
    // Use covariant return type :)
    B* DoClone() const override { return new B(*this); }
    B* DoCreate() const override { return new B; }
};


class ChildA : public A {
public:
    auto Clone() const { return std::unique_ptr<ChildA>{DoClone()}; }
    auto Create() const { return std::unique_ptr<ChildA>{DoCreate()}; }

private:
    // Use covariant return type :)
    ChildA* DoClone() const override { return new ChildA(*this); }
    ChildA* DoCreate() const override { return new ChildA; }
};

int main()
{
    ChildA childA;
    A& a = childA;
    IPrototype& prototype = a;

    // Each of the following will create a copy of `ChildA`:
    std::unique_ptr<ChildA> clone1 = childA.Clone();
    std::unique_ptr<A> clone2 = a.Clone();
    std::unique_ptr<IPrototype> clone3 = prototype.Clone();

    // Each of the following will create a new default instance `ChildA`:
    std::unique_ptr<ChildA> instance1 = childA.Create();
    std::unique_ptr<A> instance2 = a.Create();
    std::unique_ptr<IPrototype> instance3 = prototype.Create();

	cout << "Hello World!";

	return 0;
}
