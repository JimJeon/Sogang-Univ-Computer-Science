#include<stdio.h>
// 행렬 사이의 곱셈을 수행하는 함수이다.
// 인자로는 3차원 배열을 받는다.
// 첫번째 행렬은 matrix[0]에 두번째 행렬은 matrix[1]에 결과는 matrix[2]에 저장된다.
void matrixMultiple(int matrix[3][4][4]){
	int i,j,k;
	for(i=0;i<4;++i)
		for(j=0;j<4;++j)
			for(k=0;k<4;++k)
				matrix[2][i][j] += matrix[0][i][k] * matrix[1][k][j];
}

int main(void){
	int matrix[3][4][4] = {0,};
	int i,j;
	printf("First matrix:\n");
	for(i=0;i<4;++i)
		for(j=0;j<4;++j)
			scanf("%d",&matrix[0][i][j]);
	printf("Second matrix:\n");
	for(i=0;i<4;++i)
		for(j=0;j<4;++j)
			scanf("%d",&matrix[1][i][j]);
	matrixMultiple(matrix);
	printf("Result:\n");
	for(i=0;i<4;++i){
		for(j=0;j<4;++j){
			printf("%7d ",matrix[2][i][j]);
		}
		printf("\n");
	}

	return 0;
}

