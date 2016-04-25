#include<iostream>
#include<cstdlib>
#include<cstring>
#include"str.h"

Str::Str(int leng) {
    len = leng;
    str = new char[len+1];
}
Str::Str(const char *neyong) {
    len = strlen(neyong);
    str = new char[len+1];
    strncpy(str, neyong, len+1);
}
Str::~Str() {
    delete [] str;
}
int Str::length(void) {
    return len;
}
char* Str::contents(void) {
    return str;
}
int Str::compare(Str& a) {
    return strcmp(str, a.contents());
}
int Str::compare(const char *a) {
    return strcmp(str, a);
}
void Str::operator=(const char *a) {
    delete [] str;
    len = strlen(a);
    str = new char[len+1];
    strncpy(str, a, len+1);
}
void Str::operator=(Str& a) {
    delete [] str;
    len = a.length();
    str = new char[len+1];
    strncpy(str, a.contents(), len+1);
}
