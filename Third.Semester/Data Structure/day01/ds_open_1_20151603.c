#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion_sort(int* target, int n)
{
    int i, j, tmp;
    for(i = 1; i < n; ++i)
    {
        j = i;
        tmp = target[i];
        while(--j >= 0)
        {
            if(tmp < target[j]) break;
            target[j+1] = target[j];
        }
        target[j+1] = tmp;
    }
}

int main(void)
{
    int*    array;
    int     fin;
    int     i, n = 0;
    FILE*   fp;
    clock_t start;
    clock_t stop;

    if( (fp = fopen("lab1.data","r")) == NULL )
        printf("file open error");
    
    while( ~fscanf(fp, "%d", &i) ) n++;

    fclose(fp);
    if( (fp = fopen("lab1.data","r")) == NULL )
        printf("file open error");

    array = malloc( n * sizeof(int) );
    for (i = 0; i < n; ++i)
        fscanf(fp,"%d",&array[i]);

    printf("Input: ");
    for( i = 0; i < n; ++i) printf("%d ", array[i]);
    puts("");
    
    start = clock();
    insertion_sort(array, n);
    stop = clock();

    printf("Output: ");
    for( i = 0; i < n; ++i ) printf("%d ", array[i]);
    puts("");
    
    fclose(fp);

    printf("execute time: %lf\n", (((double)(stop-start)) / CLOCKS_PER_SEC));
    return 0;
}
