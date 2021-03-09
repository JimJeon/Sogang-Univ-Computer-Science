#include "myHeader.h"

int main(void)
{
    int pages = 0, i = 0;
    int ans[10] = {0,};
    int pos = 0;
    int testcase = 0;

    scanf("%d", &testcase);
    while(testcase--)
    {
        initialize(ans, 10);

        scanf("%d", &pages);
     
        pos = positional_number(pages);
        get_nums_in_pages( pages, pos, ans );
     
        for( i = 0; i < 10; ++i )
            printf("%d ",ans[i]);
        puts("");
    }
 
    return 0;
}
