#include<iostream>
#include"GrowableArray.h"
using namespace std;

template <class T>
GrowableArray<T>::GrowableArray(int size) : Array<T>(size) {}
template <class T>
GrowableArray<T>::~GrowableArray() {}
template <class T>
T& GrowableArray<T>::operator[] (int idx) {
    int length = this->len;
    T* newData = NULL;
    if( idx >= length ) {
        newData = new T[length*2];
        memset(newData, 0, length*2);
        memcpy(newData, this->data, length);
        this->len = length*2;

        delete [] this->data;
        this->data = newData;
        newData = NULL;
    }
    return Array<T>::operator[] (idx);
}
