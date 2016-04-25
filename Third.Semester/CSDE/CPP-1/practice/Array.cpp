#include<iostream>
#include"Array.h"
using namespace std;

Array::Array(int size) : len(size) {
    data = new int[size];
}
Array::~Array() {
    delete [] data;
}
int Array::length() {
    return len;
}
int& Array::operator[] (int idx) {
    static int tmp;
    if( idx < 0 || idx >= len) {
        cerr << "Array bound error!" << endl;
        return tmp;
    }
    return data[idx];
}
int Array::operator[] (int idx) const {
    if( idx < 0 || idx >= len ) {
        cerr << "Array bound error!" << endl;
        return 0;
    }
    return data[idx];
}
void Array::print() {
    cout << "[" << data[0];
    for (int i = 1; i < len; ++i)
        cout << " " << data[i];
    cout << "]" << endl;
}
