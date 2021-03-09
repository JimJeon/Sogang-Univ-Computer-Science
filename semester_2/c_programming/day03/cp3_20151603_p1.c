#include<stdio.h>
#include<math.h>

int is_prime(int ***a){
	int i;
	if(***a <= 1) return 0;
	for(i = 2;i<=sqrt(***a);++i)
		if(***a % i == 0) return 0;
	return 1;
}
	
int main(void){
	int a;
	int *pa = &a;
	int **ppa = &pa;
	scanf("%d", pa);
	printf("%d\n",is_prime(&ppa));

	return 0;
}
