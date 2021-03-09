#ifndef __ARRAY__
#define __ARRAY__

#include<iostream>
using namespace std;

class Array {
    protected:
        int *data;
        int len;
    public:
        Array(int);
        virtual ~Array();
        int length();
        int& operator[](int);
        int operator[](int) const;
        void print();
};
#endif
