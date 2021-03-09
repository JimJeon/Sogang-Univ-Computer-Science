#include<iostream>
#include"GrowableArray.h"
using namespace std;

int main(void)
{
    // GrowableArray test (int)
    cout << "GrowableArray<int> Test" << endl;
    GrowableArray<int> g(10);
    for( int i = 0; i < g.length(); ++i) g[i] = 2 * i + 3;
    cout << "g(10)"; g.print();
    g[13] = 13;
    cout << "g(26)"; g.print();
    return 0;
}
