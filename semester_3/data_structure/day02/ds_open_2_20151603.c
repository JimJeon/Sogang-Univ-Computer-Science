#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 201

typedef struct term
{
    int coef;
    int expo;
} term_t;

typedef struct polynomial
{
    int start;
    int end;
} poly_t;

bool readPoly(term_t *terms, poly_t *poly, int *avail, const char *filename)
{
    int expo_in = 0;
    int coef_in = 0;

    FILE *fp = NULL;

    int tmp;

    fp = fopen(filename, "r");
    if(!fp)
    {
        printf("File open error!\n");
        return false;
    }

    poly->start = *avail;

    while( (tmp = fscanf(fp, "%d%d", &coef_in, &expo_in)) != EOF)
    {
        terms[*avail].coef = coef_in;
        terms[(*avail)++].expo = expo_in;
    }
    poly->end = *avail - 1;

    fclose(fp);
    return true;
}
void printPoly(term_t *terms, poly_t poly)
{
    int i;
    for( i = poly.start; i <= poly.end; ++i )
        printf("(%d,%d) ",terms[i].coef, terms[i].expo);
}
poly_t padd(term_t *result_terms, term_t *terms, poly_t A, poly_t B)
{
    poly_t result;
    int i, j, cnt = 0;

    result.start = 0;
    for( i = A.start, j = B.start; i <= A.end && j <= B.end;)
    {
        if( terms[i].expo < terms[j].expo )
        {
            result_terms[cnt].coef = terms[j].coef;
            result_terms[cnt++].expo = terms[j++].expo;
            continue;
        }
        if( terms[i].expo > terms[j].expo )
        {
            result_terms[cnt].coef = terms[i].coef;
            result_terms[cnt++].expo = terms[i++].expo;
            continue;
        }
        if( terms[i].expo == terms[j].expo )
        {
            result_terms[cnt].expo = terms[i].expo;
            result_terms[cnt++].coef = terms[i++].coef + terms[j++].coef;
            continue;
        }

    }
    
    if( i > A.end )
    {
        for( ; j <= B.end ; ++j, cnt++)
        {
            result_terms[cnt].expo = terms[j].expo;
            result_terms[cnt].coef = terms[j].coef;
        }
    }
    if( j > B.end )
    {
        for( ; i <= A.end ; ++i, cnt++)
        {
            result_terms[cnt].expo = terms[i].expo;
            result_terms[cnt].coef = terms[i].coef;
        }
    }
    


    result.end = cnt - 1;

    return result;
}
int main(void)
{
    term_t terms[MAX_SIZE], result_terms[MAX_SIZE];

    poly_t A, B, result;

    int avail = 0;
    int i;

    readPoly(terms, &A, &avail, "A.txt");
    readPoly(terms, &B, &avail, "B.txt");

    result = padd(result_terms, terms, A, B);

    printPoly(result_terms, result);

    return 0;
}
