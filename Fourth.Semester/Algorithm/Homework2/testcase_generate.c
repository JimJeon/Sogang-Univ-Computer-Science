#include<stdio.h>
#include<stdlib.h>
#include"data.h"
#include<string.h>
#include<time.h>

int main(void) {
    ELEMENT* elements = NULL;
    int data_cnt = 10000000;
    int i;
    FILE* fp = NULL;

    fp = fopen("INPUT.bin", "wb");
    if(!fp) {
        fprintf(stderr, "file open error");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    elements = calloc(data_cnt, sizeof(*elements));
    if(!elements) {
        fprintf(stderr, "memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < data_cnt; ++i) {
        elements[i].score = rand();
        elements[i].data[0] = rand() / 2.0;
        elements[i].data[1] = rand() / 3.0;
        elements[i].data[2] = rand() / 5.0;
        strncpy(elements[i].comments, "hello world",11);
    }

    fwrite(elements,sizeof(*elements), data_cnt, fp); 


    fclose(fp);
    fp = fopen("INPUT.txt", "wt");

    for(i = 0; i < data_cnt; ++i) {
        fprintf(fp, "%d\n", elements[i].score);
    }
    
    fclose(fp);

    free(elements);
    return 0;
}
