#include<stdio.h>

void mat_mul(int a[100][100],int b[100][100],int c[100][100],int N){
	int i,j,k;
	for (i = 0; i < N; i++) 
		for (j = 0; j < N; j++) 
			for (k = 0; k < N; k++) 
				*(*(c+i)+j) += *(*(a+i)+k)* *(*(b+k)+j);
}


int main(void){
	int number;
	int matrix_a[100][100],matrix_b[100][100];
	int matrix_answer[100][100] = {0,};
	int i,j;

	scanf("%d",&number);

	for (i = 0; i < number; i++) 
		for (j = 0; j < number; j++) 
			scanf("%d",(*(matrix_a+i)+j));
	for (i = 0; i < number; i++) 
		for (j = 0; j < number; j++) 
			scanf("%d",(*(matrix_b+i)+j));

	mat_mul(matrix_a,matrix_b,matrix_answer,number);

	for (i = 0; i < number; i++) {
		for (j = 0; j < number; j++) {
			printf("%d ",*(*(matrix_answer+i)+j));
		}
		printf("\n");
	}

	return 0;
}
