#include "StackIter.h"

StackIter::StackIter(const Stack* s)
{
    stk = s;
}
void StackIter::first()
{
    index = 0;
}
void StackIter::next()
{
    index++;
}
bool StackIter::isDone()
{
    return index == (stk->sp + 1);
}
int StackIter::currentItem()
{
    return stk->items[index];
}