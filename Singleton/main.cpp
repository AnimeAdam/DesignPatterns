//Singleton a global static object that can be accessed anywhere.

#include "Singleton.h"

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton* Singleton::instance = 0;

int main() {
    Singleton* s = s->getInstance();
    cout << s->getData() << endl;
    s->setData(100);
    cout << s->getData() << endl;
    return 0;
}