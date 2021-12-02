#pragma once

#include <iostream>

using namespace std;

class Singleton {

private:
    static Singleton* instance;
    int data;

    // Private constructor so that no objects can be created.
    Singleton() {
        data = 0;
    }

public:
    static Singleton* getInstance() {
        if (!instance)
            instance = new Singleton;
        return instance;
    }

    int getData() {return this->data; }
    void setData(int data) {this->data = data; }

//OR with a private constructor
//public:
//    static Singleton& instance()
//    {
//        static Singleton* instance = new Singleton();
//        return *instance;
//    }
//
//private:
//    Singleton() {}

};