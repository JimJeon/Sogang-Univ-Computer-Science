#include<iostream>
#include<cstdlib>
#include<cstring>
#include"str.h"

Str::Str(int leng) : len(leng) {
    this->str = new char[this->len+1];
}
Str::Str(const char *neyong) : len(strlen(neyong)) {
    this->str = new char[this->len+1];
    strncpy(this->str, neyong, this->len+1);
}
Str::~Str() {
    delete [] this->str;
}
int Str::length(void) {
    return this->len;
}
char* Str::contents(void) {
    return this->str;
}
int Str::compare(Str& a) {
    return strcmp(this->str, a.contents());
}
int Str::compare(const char *a) {
    return strcmp(this->str, a);
}
void Str::operator=(const char *a) {
    delete [] this->str;
    len = strlen(a);
    this->str = new char[this->len+1];
    strncpy(this->str, a, this->len+1);
}
void Str::operator=(Str& a) {
    delete [] this->str;
    this->len = a.length();
    this->str = new char[this->len+1];
    strncpy(this->str, a.contents(), this->len+1);
}
