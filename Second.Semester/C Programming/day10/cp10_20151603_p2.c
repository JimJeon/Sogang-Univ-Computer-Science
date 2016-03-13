#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char *user_input = (char*)malloc(17*sizeof(char));
	char *key_value = "BKMGTP";
	int i, length = 0;
	
	scanf("%16s",user_input);

	for(i = 0;*(user_input+i)!='\0';++i)
		length++;
	for(i = 0;i < length % 3;++i)
		printf("%c",*(user_input+i));
	if(length % 3 == 0)
		printf("%c%c%c",*user_input,*(user_input+1),*(user_input+2));

	printf("%c\n",*(key_value+(length-1)/3));

	return 0;

}		
