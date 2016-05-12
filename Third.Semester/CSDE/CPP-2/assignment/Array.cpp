#include<iostream>
#include"Array.h"
using namespace std;

template <typename T>
Array<T>::Array(int size) {
    if(size <= 0) {
        cerr << "Array size error!" << endl;
        ~Array();
    }
    else {
        this->len = size;
        data = new T[size];
    }
}
template <typename T>
Array<T>::~Array() {
    delete [] data;
}
template <typename T>
int Array<T>::length() {
    return len;
}
template <typename T>
T& Array<T>::operator[](int idx) {
    static int tmp;
    if( idx < 0 || idx >= len ) {
        cerr << "Array bound error!" << endl;
        return tmp;
    }
    return data[idx];
}
template <typename T>
T Array<T>::operator[](int idx) const {
    if( idx < 0 || idx >= len ) {
        cerr << "Array bound error!" << endl;
        return 0;
    }
    return data[idx];
}
template <typename T>
void Array<T>::print() {
    cout << "[" << data[0];
    for (int i = 1; i < len; ++i)
        cout << " " << data[i];
    cout << "]" << endl;
}
