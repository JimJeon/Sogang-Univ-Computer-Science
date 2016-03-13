#include<stdio.h>
#include<stdlib.h>

int main(void){
	int number;
	int user_input;
	int *count;
	int i;

	scanf("%d",&number);

	count = (int*)calloc(10000,sizeof(int));

	for (i = 0; i < number; ++i){
		scanf("%d",&user_input);
		count[user_input-1]++;
	}

	for(i = 0;i < 10000;++i)
		if(count[i])
			printf("%d %d\n",i+1,count[i]);

	free(count);

	return 0;
}
