#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void split_string(char *str,char *string_1,char *string_2);

int main(void)
{
	char str[51];
	int length;
	char *str1,*str2;

	printf("input str : ");
	gets(str);

	length = strlen(str);
	str1 = (char*)malloc((length/2+1) * sizeof(char));
	str2 = (char*)malloc((length/2+1) * sizeof(char));

	split_string(str,str1,str2);

	printf("[%s] -> [%s] [%s]\n",str,str1,str2);

	free(str1);
	free(str2);

	return 0;
}

void split_string(char *str,char *string_1,char *string_2)
{
	int length = strlen(str);
	strncpy(string_1,str,length/2);
	*(string_1+length/2) = '\0';
	strncpy(string_2,str+length/2,length/2);
	*(string_2+length/2) = '\0';

	return;
}
