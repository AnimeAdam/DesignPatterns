//The Chain of Responsibility pattern is designed to 
//chain the receiving objects and pass the request along the chain until an object handles it.

//An object-oriented linked list with recursive traversal.

#include "Handler1.h"
#include "Handler2.h"
#include "Handler3.h"

int main()
{
    srand(time(0));
    Handler1 root;
    Handler2 two;
    Handler3 thr;
    root.add(&two);
    root.add(&thr);
    thr.setNext(&root);
    for (int i = 1; i < 10; i++)
    {
        root.handle(i);
        cout << '\n';
    }
}