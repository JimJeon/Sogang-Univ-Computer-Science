#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *my_strncpy(char *a,char *b,int n);
void initialization(char *a,int n);

int main(void)
{
	char str[20];
	char *str1;
	int i;

	printf("input str : ");
	gets(str);

	str1 = (char*)malloc((strlen(str)+1) * sizeof(char));
	strcpy(str1,str);

	for(i = 0;i < strlen(str1) + 1; ++i)
	{
		initialization(str1,strlen(str1));
		my_strncpy(str1,str,i);
		printf("%s\n",str1);
	}

	free(str1);

	return 0;
}

char *my_strncpy(char *a,char *b,int n)
{
	int i;
	for(i = 0;i < n; ++i)
		*(a+i) = *(b+i);
	return a;
}

void initialization(char *a,int n)
{
	int i;
	for(i = 0;i < n; ++i)
		*(a+i) = '*';
	return;
}
