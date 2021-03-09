#include<iostream>
#include"RangeArray.h"
using namespace std;

RangeArray::RangeArray(int start, int end) : 
    Array(end - start + 1), low(start), high(end) {}   
RangeArray::~RangeArray() {}
int RangeArray::baseValue() {
    return this->low;
}
int RangeArray::endValue() {
    return this->high;
}
int& RangeArray::operator[] (int idx) {
    return Array::operator[] (idx - this->low);
}
int RangeArray::operator[] (int idx) const {
    return Array::operator[] (idx - this->low);
}
