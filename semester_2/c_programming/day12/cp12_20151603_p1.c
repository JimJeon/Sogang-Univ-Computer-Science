#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int strCmpPk(char *s1,char *s2);
void strPk(char *s1,char *s2);

int main(void)
{
	char first_str[100];
	char second_str[100];

	int check;

	printf("first string : ");
	scanf("%s",first_str);
	printf("second string : ");
	scanf("%s",second_str);

	check = strCmpPk(first_str,second_str);
	if(check < 0)
		printf("string1 < string2\n");
	else if(check > 0)
		printf("string1 > string2\n");
	else
		printf("string1 == string2\n");

	return 0;
}

void strPk(char *s1,char *s2)
{
	int i,j;

	for(i = 0;i <= (int)strlen(s1); ++i)
	{
		if(!('a'<=s1[i] && s1[i]<='z') && !('A'<=s1[i] && s1[i]<='Z') && !(s1[i] == '\0'))
		{
			for(j = i;j < (int)strlen(s1); ++j)
				s1[j] = s1[j+1];
			i -= 1;
		}
	}
	for(i = 0;i <= (int)strlen(s2); ++i)
	{
		if(!('a'<=s2[i] && s2[i]<='z') && !('A'<=s2[i] && s2[i]<='Z') && !(s1[i] == '\0'))
		{
			for(j = i;j < (int)strlen(s2); ++j)
				s2[j] = s2[j+1];
			i -= 1;
		}
	}

	return;
}

int strCmpPk(char *s1,char *s2)
{
	strPk(s1,s2);

	return strcmp(s1,s2);
}
