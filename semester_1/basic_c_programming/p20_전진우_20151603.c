#include<stdio.h>
int main(void){
	int number,cutline,i=0;
	int score,average=0,failure=0;
	printf("Number of class: ");
	scanf("%d",&number);
	printf("Cutline: ");
	scanf("%d",&cutline);
	while(number){
		printf("input score #%d: ",i);
		scanf("%d",&score);
		if (score < cutline) failure++;
		average += score;
		number--; i++;
	}
	printf("Average score: %.2f\n",average/(float)i);
	printf("Number of failures: %d\n",failure);
	return 0;
}
