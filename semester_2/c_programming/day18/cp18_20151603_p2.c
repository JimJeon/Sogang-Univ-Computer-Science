#include<stdio.h>
#include<string.h>

typedef union
{
	char Short[10];
	char Medium[30];
	char Long[50];
} Name;

int main(void)
{
	Name name;
	char tmp_str[100];
	int length;

	printf("Type the string : ");
	scanf("%s",tmp_str);

	length = strlen(tmp_str);

	if(0<=length&&length<10)
	{
		puts("Saved in Short Size.");
		strcpy(name.Short,tmp_str);
	}
	else if(10<=length&&length<30)
	{
		puts("Saved in Medium Size.");
		strcpy(name.Medium,tmp_str);
	}
	else if(30<=length&&length<50)
	{
		puts("Saved in Long Size.");
		strcpy(name.Long,tmp_str);
	}

	printf("Size of Data : %d\n",(int)sizeof(name));

	return 0;
}
/*
 * 공용체의 크기가 50바이트로 나오는 이유는 다음과 같다.
 * 공용체는 그 안에 있는 변수들이
 * 공용체 내부의 공간을 나누어 쓰는 타입이다.
 *
 * 그런데 10바이트 변수, 30바이트 변수, 50바이트 변수가
 * 있으면 그 중에 50바이트 변수를 사용할 수 있어야 하므로
 * 크기르 50만큼 잡아놓고
 *
 * 10바이트 변수를 사용할 때는 50중에서 10바이트만
 * 30바이트 변수를 사용할 때는 50중에서 30바이트만
 * 50바이트 변수를 사용할 때는 50중에서 50바이트를 모두 사용한다.
 */
