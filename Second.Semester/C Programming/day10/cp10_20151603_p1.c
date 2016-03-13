#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int size = 10;
	char* user_input = (char*)malloc(sizeof(char) * size);
	int i = 0, num_of_space = 0;
	int flag = 0;
	
	while(*(user_input+i-1) != '\n')
	{
		scanf("%c",user_input+i);
		if(i == size)
		{
			size += 10;
			user_input = (char*)realloc(user_input,size);
		}
		i += 1;
	}
	*(user_input+i-1) = '\0';

	i = 0;


	for(;*(user_input+i) != '\0';++i)
	{
		if(*(user_input+i) == ' ')
		{
			flag = 0;
			continue;
		}
		if(flag == 1)
			continue;

		if(*(user_input+i) != ' ')
		{
			flag = 1;
			num_of_space += 1;
		}
	}

	printf("%d\n",num_of_space);

	return 0;
}
