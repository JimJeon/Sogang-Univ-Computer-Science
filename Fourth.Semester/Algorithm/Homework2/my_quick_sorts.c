#include "my_quick_sorts.h"

void qsort_orig(void* base, size_t nmem, size_t size, _Cmpfun* compar) {
    int pivot = 0;
    if(nmem) {
        pivot = partition(base, nmem, size, compar);
        qsort_orig(base, pivot, size, compar);
        qsort_orig(base + (pivot + 1) * size, nmem - pivot - 1, size, compar);
    }
}

void qsort_median_insert(void* base, size_t nmem, size_t size, _Cmpfun* compar) {
    int pivot = 0;
    if(nmem <= 5) {
        insertion_sort(base, nmem, size, compar);
        return;
    }
    pivot = (int)((median(base, base + (nmem - 1) * size, base + (nmem / 2) * size, compar) - base) / size);
    swap(base, base + pivot * size, size);
    partition(base, nmem, size, compar);
    qsort_median_insert(base, pivot, size, compar);
    qsort_median_insert(base + (pivot + 1) * size, nmem - pivot - 1, size, compar);
    insertion_sort(base, nmem, size, compar);
}

void qsort_median_insert_iter(void* base, size_t nmem, size_t size, _Cmpfun* compar) {
    while(1<nmem) {
        size_t i = 0;
        size_t j = nmem-1;
        char* qi = (char*)base;
        char* qj = qi + size*j;
        char* qp = qj;

        while(i < j) {
            while(i < j && (*compar)(qi, qp) <= 0)
                ++i, qi += size;
            while(i < j && (*compar)(qp, qj) <= 0)
                --j, qj -= size;

            if(i < j) {
                char buf[256];
                char* q1 = qi;
                char* q2 = qj;
                size_t m, ms;

                for(ms = size; 0 < ms; ms -= m, q1 += m, q2 += m) {
                    m = (ms < sizeof(buf)) ? ms : sizeof(buf);
                    memcpy(buf, q1, m);
                    memcpy(q1, q2, m);
                    memcpy(q2, buf, m);
                }
                ++i, qi += size;
            }
        }
        if(qi != qp) {
            char buf[256];
            char *q1 = qi;
            char* q2 = qp;
            size_t m, ms;

            for(ms = size; 0 < ms; ms -= m, q1 += m, q2 += m) {
                m = (ms < sizeof(buf))?ms:sizeof(buf);
                memcpy(buf, q1, m);
                memcpy(q1, q2, m);
                memcpy(q2, buf, m);
            }
        }
        j = nmem - i - 1, qi += size;
        if(j < i) {
            if(1 < j)
                qsort_median_insert_iter(qi, j, size, compar);
            nmem = i;
        } else {
            if(1 < i)
                qsort_median_insert_iter(base, i, size, compar);
            base = qi;
            nmem = j;
        }
    }
}

void qsort_final(void* base, size_t nmem, size_t size, _Cmpfun* compar) {
    qsort(base, nmem, size, compar);
}

void swap(void* a, void* b, size_t size) {
    void* tmp = calloc(1, size);
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
    free(tmp);
}

void* median(void* a, void* b, void* c, _Cmpfun* compar) {
    if(compar(a,b) < 0) {
        if(compar(b,c) < 0) return b;
        if(compar(c,a) < 0) return a;
        return c;
    } else {
        if(compar(a,c) < 0) return a;
        if(compar(c,b) < 0) return b;
        return c;
    }
}

void insertion_sort(void* base, size_t nmem, size_t size, _Cmpfun* compar) {
    int i, j;
    void* tmp = NULL;
    if(nmem <= 1) return;

    tmp = calloc(1, size);
    for(i = 1; i < nmem; ++i) {
        j = i - 1;
        memcpy(tmp, base + i * size, size);
        while(j >= 0 && compar(base + j * size, tmp) > 0) {
            memcpy(base + (j+1) * size, base + j * size, size);
            j = j - 1;
        }
        memcpy(base + (j+1) * size, tmp, size);
    }
    free(tmp);
}

int partition(void* base, size_t nmem, size_t size, _Cmpfun* compar) {
    int pivot = 1;
    int i;

    for(i = 1; i < nmem; ++i) {
        if(compar(base + i * size, base) < 0){
            swap(base + i * size, base + pivot * size, size);
            pivot = pivot + 1;
        }
    }
    pivot = pivot - 1;
    swap(base, base + pivot * size, size);
    return pivot;
}
