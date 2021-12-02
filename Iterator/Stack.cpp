#include "Stack.h"


Stack::Stack()
{
    sp = -1;
}
void Stack::push(int in)
{
    items[++sp] = in;
}
int Stack::pop()
{
    return items[sp--];
}
bool Stack::isEmpty()
{
    return (sp == -1);
}
StackIter* Stack::createIterator()const // 2. Add a createIterator() member
{
    return new StackIter(this);
}