#ifndef __MY_QUICK_SORTS_H__
#define __MY_QUICK_SORTS_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

typedef int _Cmpfun(const void*, const void*);

void qsort_orig(void* base, size_t nmem, size_t size, _Cmpfun* compar);
void qsort_median_insert(void* base, size_t nmem, size_t size, _Cmpfun* compar);
void qsort_median_insert_iter(void* base, size_t nmem, size_t size, _Cmpfun* compar);
void qsort_final(void* base, size_t nmem, size_t size, _Cmpfun* compar);
void insertion_sort(void* base, size_t nmem, size_t size, _Cmpfun* compar);
int partition(void* base, size_t nmem, size_t size, _Cmpfun* compar);
void* median(void* a, void* b, void* c, _Cmpfun* compar);
void swap(void* a, void* b, size_t size);

#endif
