#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
	int *randNumbers = (int*)malloc(sizeof(int)*5);
	int number;
	int size = 0;
	int i;

	srand((unsigned)time(NULL));

	for(;;){
		size++;
		if(size>5)
			randNumbers = (int*)realloc(randNumbers,sizeof(int)*size);
		number = rand()%10;
		randNumbers[size-1] = number;

		if(number == 5){
			for (i = 0; i < size; i++)
				printf("%d",randNumbers[i]);
			puts("");
			break;
		}
	}
	
	for(i=1;i<=size;++i)
		printf("%d",randNumbers[size-i]);
	puts("");
	
	free(randNumbers);
	return 0;
}
