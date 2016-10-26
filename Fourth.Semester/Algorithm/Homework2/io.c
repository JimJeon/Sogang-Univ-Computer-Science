#include "io.h"

ELEMENT* read_data(const char* filename, int cnt) {
    FILE *fp = NULL;
    ELEMENT* elements = NULL;

    fp = fopen(filename, "rb");
    if(!fp) {
        fprintf(stderr, "File open error");
        exit(EXIT_FAILURE);
    }
    elements = calloc(cnt, sizeof(*elements));
    if(!elements) {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    fread(elements,sizeof(*elements), cnt, fp); 
    fclose(fp);
    return elements;
}

void write_data(const char* filename, int cnt, ELEMENT* elements) {
    FILE* fp = NULL;

    fp = fopen(filename, "wb");
    if(!fp) {
        fprintf(stderr, "File open error");
        exit(EXIT_FAILURE);
    }

    fwrite(elements, sizeof(*elements), cnt, fp);
    fclose(fp);
}
