#ifndef __IO_H__
#define __IO_H__

typedef struct _1d_info_t {
    int *data;
    int number;
} _1d_info_t;

typedef struct _2d_info_t {
    int **data;
    int number;
} _2d_info_t;

typedef struct _1d_result_t {
    int max;
    int left;
    int right;
} _1d_result_t;

typedef struct _2d_result_t {
    int max;
    int left;
    int right;
    int up;
    int down;
} _2d_result_t;

#include<stdio.h>
#include<stdlib.h>

_1d_info_t* one_dim_read_info(const char* filename) {
    _1d_info_t* info = NULL;
    FILE *fp = NULL;
    size_t filesize = 0;

    info = calloc(1,sizeof(*info));
    if(!info) {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    fp = fopen(filename, "r");
    if(!fp) {
        fprintf(stderr, "File open error");
        exit(EXIT_FAILURE);
    }

    filesize = fread( &(info->number), sizeof(int), 1, fp );

    info->data = calloc(info->number, sizeof( *(info->data) ));
    if(!info->data) {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    filesize = fread(info->data, sizeof(int), info->number, fp);

    fclose(fp);
    return info;
}

_2d_info_t* two_dim_read_info(const char* filename) {
    _2d_info_t* info = NULL;
    FILE* fp = NULL;
    size_t filesize = 0;
    int i;

    info = malloc(sizeof(*info));
    if(!info) {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    fp = fopen(filename, "r");
    if(!fp) {
        fprintf(stderr, "File open error");
        exit(EXIT_FAILURE);
    }

    filesize = fread( &(info->number), sizeof(int), 1, fp );
    info->data = calloc(info->number, sizeof( *(info->data) ));
    if(!info->data) {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < info->number; ++i) {
        info->data[i] = calloc(info->number, sizeof( *(info->data[i]) ));
        if(!info->data[i]) {
            fprintf(stderr, "Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        filesize = fread(info->data[i], sizeof(int), info->number, fp);
    }

    fclose(fp);
    return info;
}

void one_dim_write_info (const char* filename, _1d_result_t* result) {
    FILE* fp = NULL;

    fp = fopen(filename, "w");
    if(!fp) {
        fprintf(stderr, "File open error");
        exit(EXIT_FAILURE);
    }
    fwrite(&result->max, sizeof(int), 1, fp);
    fwrite(&result->left, sizeof(int), 1, fp);
    fwrite(&result->right, sizeof(int), 1, fp);

    fclose(fp);
    return;
}

void two_dim_write_info (const char* filename, _2d_result_t* result) {
    FILE* fp = NULL;

    fp = fopen(filename, "w");
    if(!fp) {
        fprintf(stderr, "File open error");
        exit(EXIT_FAILURE);
    }

    fwrite(&result->max, sizeof(int), 1, fp);
    fwrite(&result->up, sizeof(int), 1, fp);
    fwrite(&result->left, sizeof(int), 1, fp);
    fwrite(&result->down, sizeof(int), 1, fp);
    fwrite(&result->right, sizeof(int), 1, fp);
    
    fclose(fp);
    return;
}
#endif
