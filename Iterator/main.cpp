//The Iterator pattern is like a normal iterator but for objects
//with extra funtionality.

//This is a good example of why you should make a header and cpp file
//if this was all done in only header files the complier would get confused
//and will not understand when the code is declared and when it's defined.
#include <iostream>
#include "Stack.h"
#include "StackIter.h"
#include "StackOperators.h"

using namespace std;

int main()
{
    Stack s1;
    for (int i = 1; i < 5; i++)
        s1.push(i);
    Stack s2(s1), s3(s1), s4(s1), s5(s1);
    s3.pop();
    s5.pop();
    s4.push(2);
    s5.push(9);
    cout << "1 == 2 is " << (s1 == s2) << endl;
    cout << "1 == 3 is " << (s1 == s3) << endl;
    cout << "1 == 4 is " << (s1 == s4) << endl;
    cout << "1 == 5 is " << (s1 == s5) << endl;
}