#include "myHeader.h"

int positional_number(int number)
{
    int cnt = 0;
    while( number )
    {
        cnt++;
        number /= 10;
    }
    return cnt;
}

int power_base10(int number)
{
    if(number <= 0) return 1;
    return 10 * power_base10(number - 1);
}

void initialize (int* target, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        target[i] = 0;
}
