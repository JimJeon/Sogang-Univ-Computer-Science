#include "io.h"
#include "my_quick_sorts.h"

int compare_function(const void* a, const void* b);

int main(int argc, char** argv) {
    int algo_num = 0;
    int data_cnt = 0;
    char filename[20];

    FILE* fp = NULL;

    ELEMENT* elements = NULL;

    fp = fopen("HW2_commands.txt", "rt");
    if(!fp) {
        fprintf(stderr, "File open error");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%d", &algo_num);
    fscanf(fp, "%d", &data_cnt);
    fscanf(fp, "%s", filename);
    elements = read_data(filename, data_cnt);

    switch(algo_num) {
        case 1:
            qsort(elements, data_cnt, sizeof(ELEMENT), compare_function);
            break;
        case 21:
            qsort_orig(elements, data_cnt, sizeof(ELEMENT), compare_function);
            break;
        case 22:
            qsort_median_insert(elements, data_cnt, sizeof(ELEMENT), compare_function);
            break;
        case 23:
            qsort_median_insert_iter(elements, data_cnt, sizeof(ELEMENT), compare_function);
            break;
        case 24:
            qsort_final(elements, data_cnt, sizeof(ELEMENT), compare_function);
            break;
    }
    fscanf(fp, "%s", filename);
    write_data(filename, data_cnt, elements);

    fclose(fp);
    free(elements);
    exit(EXIT_SUCCESS);
}

int compare_function(const void* a, const void* b) {
    ELEMENT* A = (ELEMENT*)a;
    ELEMENT* B = (ELEMENT*)b;

    if(A->score < B->score) return -1;
    if(A->score == B->score) return 0;
    if(A->score > B->score) return 1;
}
