#include<iostream>
#include"Array.h"
using namespace std;

Array::Array(int size) : len(size) {
    this->data = new int[size];
}
Array::~Array() {
    delete [] this->data;
}
int Array::length() {
    return this->len;
}
int& Array::operator[] (int idx) {
    static int tmp;
    if( idx < 0 || idx >= this->len) {
        cerr << "Array bound error!" << endl;
        return tmp;
    }
    return this->data[idx];
}
int Array::operator[] (int idx) const {
    if( idx < 0 || idx >= this->len ) {
        cerr << "Array bound error!" << endl;
        return 0;
    }
    return this->data[idx];
}
void Array::print() {
    cout << "[" << this->data[0];
    for (int i = 1; i < this->len; ++i)
        cout << " " << this->data[i];
    cout << "]" << endl;
}
