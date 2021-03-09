#include<stdio.h>
int main(void){
	int number;
	int pascalTriangle[20][20];
	int level, row;
	printf("input size of triangle : ");
	scanf("%d",&number);
	//level과 row로 나누어 값을 구한다.
	for(level=0;level<number;++level){
		for(row=0;row<=level;++row){
			//첫번째 단계 이거나 첫번째 혹은 마지막 행이면 값에 1을 넣는다.
			if(level == 0||row == 0||row == level){
				pascalTriangle[level][row] = 1;
				continue;
			}
			// 파스칼 삼각형의 일반항이다.
			// P(level,row) = P(level-1,row-1) + P(level-1,row)
			pascalTriangle[level][row] = pascalTriangle[level-1][row-1] + pascalTriangle[level-1][row];
		}
	}
	for(level=0;level<number;++level){
		for(row=0;row<=level;++row){
			printf("%-3d ",pascalTriangle[level][row]);
		}
		printf("\n");
	}

	return 0;
}
