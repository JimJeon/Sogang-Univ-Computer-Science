#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int row, col, value;
} Term;

Term* readMatrix()
{
    Term *input = malloc(sizeof(Term));
    FILE *fp = fopen("A.txt", "r");
    int cnt = 0, i = 0, j = 0;
    int temp_input = 0;
    
    fscanf(fp,"%d %d", &input[0].row, &input[0].col);

    for( i = 0; i < input[0].row; ++i )
    {
        for( j = 0; j < input[0].col; ++j )
        {
            fscanf(fp, "%d", &temp_input);
            if ( temp_input )
            {
                cnt++;
                input = realloc(input, (cnt+1) * sizeof(Term));
                input[cnt].row = i;
                input[cnt].col = j;
                input[cnt].value = temp_input;
            }
        }
    }
    input[0].value = cnt;
    fclose(fp);
    return input;
}
Term* fast_transpose(Term *input)
{
    Term* output = NULL;
    int *row_terms = calloc(input[0].col, sizeof(int));
    int i = 0, j = 0, k = 0;

    output = malloc((input[0].value+1) * sizeof(Term));
    output[0].row = input[0].col;
    output[0].col = input[0].row;
    output[0].value = input[0].value;

    for( i = 1; i <= input[0].value; ++i )
        row_terms[input[i].col]++;
    j = row_terms[0];
    row_terms[0] = 1;
    for( i = 1; i < input[0].col; ++i )
    {
        k = j;
        j = row_terms[i];
        row_terms[i] = row_terms[i-1] + k;
    }
    for( i = 1; i <= input[0].value; ++i )
    {
        j = row_terms[input[i].col]++;
        output[j].row = input[i].col;
        output[j].col = input[i].row;
        output[j].value = input[i].value;
    }

    free(input);
    free(row_terms);
    return output;
}

void printMatrix(Term *output)
{
    int i = 0;
    for( i = 0;i <= output[0].value; ++i )
        printf("%d %d %d\n", output[i].row, output[i].col, output[i].value);
}
int main(void)
{
    Term *term = NULL;

    term = readMatrix();
    term = fast_transpose(term);
    printMatrix(term);

    free(term);
    return 0;
}
