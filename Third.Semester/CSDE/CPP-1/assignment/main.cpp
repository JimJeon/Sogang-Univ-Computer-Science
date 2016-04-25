#include<iostream>
#include "str.h"
using namespace std;

int main(void)
{
    Str a("I'm a girl");
    Str b("I'm a man");
    cout << a.contents();
    a = "I'm a boy\n";
    cout << a.contents();
    cout << a.compare("I'm a a") << endl;

    cout << a.compare(b) << endl;

    a = b;

    cout << a.contents() << endl;
    return 0;
}
