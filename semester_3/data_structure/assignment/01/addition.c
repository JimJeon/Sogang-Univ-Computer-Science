#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 1024

typedef struct
{
    int row;
    int col;
    int value;
} term_t;
typedef term_t* matrix_t;

matrix_t matrix_addition (matrix_t, matrix_t);
matrix_t read_matrix (const char*);
void print_matrix (matrix_t);

int main(void)
{
    matrix_t A = NULL;
    matrix_t B = NULL;
    matrix_t S = NULL;

    A = read_matrix("A.txt");
    B = read_matrix("B.txt");
    S = matrix_addition(A, B);
    print_matrix(S);
    //print_matrix(A);
    //print_matrix(B);

    if(A) free(A);
    if(B) free(B);
    if(S) free(S);

    exit(0);
}

matrix_t matrix_addition (matrix_t A, matrix_t B)
{
    matrix_t S = calloc(MAX_TERMS, sizeof(term_t));
    int i, j, cnt = 0;

    if( A[0].row != B[0].row || A[0].col != B[0].col)
    {
        fprintf(stderr, "Error: Invalid Matrices");
        return NULL;
    }

    S[cnt].row = A[0].row;
    S[cnt++].col = A[0].col;

    for(i = 1, j = 1;i <= A[0].value, j<= B[0].value;)
    {
        if( A[i].row > B[j].row )
        {
            S[cnt].row = B[j].row;
            S[cnt].col = B[j].col;
            S[cnt++].value = B[j++].value;
        }
        else if( B[j].row > A[i].row )
        {
            S[cnt].row = A[i].row;
            S[cnt].col = A[i].col;
            S[cnt++].value = A[i++].value;
        }
        else
        {
            if( A[i].col > B[j].col )
            {
                S[cnt].row = B[j].row;
                S[cnt].col = B[j].col;
                S[cnt++].value = B[j++].value;
            }
            else if( B[j].col > A[i].col )
            {
                S[cnt].row = A[i].row;
                S[cnt].col = A[i].col;
                S[cnt++].value = A[i++].value;
            }
            else
            {
                S[cnt].row = A[i].row;
                S[cnt].col = A[i].col;
                S[cnt++].value = A[i++].value + B[j++].value;
            }
        }
    }
    while( i <= A[0].value )
    {
        S[cnt].row = A[i].row;
        S[cnt].col = A[i].col;
        S[cnt++].value = A[i++].value;
    }
    while( j <= B[0].value )
    {
        S[cnt].row = B[j].row;
        S[cnt].col = B[j].col;
        S[cnt++].value = B[j++].value;
    }
    S[0].value = cnt - 1;
    return S;
}
    
matrix_t read_matrix (const char* filename)
{
    FILE *fp = fopen(filename, "r");
    matrix_t matrix = calloc(MAX_TERMS, sizeof(term_t));
    int i, j, cnt = 0, temp = 0;

    if(fp == NULL)
    {
        fprintf(stderr, "Error: File Open Error");
        return NULL;
    }

    fscanf(fp, "%d %d", &matrix[0].row, &matrix[0].col);
    for(i = 0;i < matrix[0].row; ++i)
    {
        for(j = 0;j < matrix[0].col; ++j)
        {
            fscanf(fp, "%d", &temp);
            if(temp)
            {
                cnt++;
                matrix[cnt].row = i;
                matrix[cnt].col = j;
                matrix[cnt].value = temp;
            }
        }
    }
    fclose(fp);
    matrix[0].value = cnt;
    return matrix;
}
void print_matrix (matrix_t matrix)
{
    int i = 0;
    for(i = 0;i <= matrix[0].value; ++i)
        printf("%d %d %d\n", matrix[i].row, matrix[i].col, matrix[i].value);
}
