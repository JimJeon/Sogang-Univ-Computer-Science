#include<stdio.h>
int main(void){
	int number[10];
	int max,min;
	int i,tmp;
	printf("Input (10 numbers): ");
	for(i=0;i<10;++i){
		scanf("%d",&number[i]);
		if (i==0){
			max = number[i];
			min = number[i];
		}

		if (max<number[i]) max = number[i];
		if (min>number[i]) min = number[i];
	}
	for(i=0;i<5;++i){
		tmp = number[i];
		number[i] = number[9-i];
		number[9-i] = tmp;
	}
	for(i=0;i<10;++i) printf("%d ",number[i]);
	printf("\nMax: %d, Min: %d\n",max,min);
	return 0;
}

