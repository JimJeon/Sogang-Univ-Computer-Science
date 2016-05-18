#include "myHeader.h"

void get_nums_in_pages(int number, int pos, int* ans)
{
    int low_ans[10] = {0,};
    int i = 0;
    int base10 = power_base10( pos - 1 );
    int single_num = 0;
    int other_num = 0;
 
    if( !pos ) return;
 
    single_num = number / base10;
    other_num = number - single_num * base10;
 
    for( i = 0; i < single_num; ++i )
        ans[i] = base10;
    for( i = 0; i < 10; ++i )
        ans[i] += (int)(0.1* single_num * base10 * (pos - 1));
    ans[single_num] += other_num + 1;
 
    get_nums_in_pages( other_num, pos - 1, low_ans );
 
    for( i = 0; i < 10; ++i )
        ans[i] += low_ans[i];
 
    ans[0] -= base10;
 
    return;
}
