#include <stdio.h>

void printOne (int);
void sqr (int);

int main()
{
	// Declaration
	int number;

	// Input
	printf("Input : ");
	scanf("%d",&number);
	
	// Excute
	sqr(number);
	

	return 0;
}

// 받은 인자를 "Result : 인자" 형식으로 출력하는 출력함수이다.
// 정수 인자를 받는다.
void printOne (int a)
{
	printf("Result : %d\n",a);
}

// 받은 인자를 제곱한 뒤에 출력함수 printOne을 호출하고 함수 실행의 결과값 Result를 전달한다.
// 제곱할 정수 인자를 받는다.
void sqr (int a)
{
	int result;
	result = a*a; // 인자를 제곱
	printOne (result); // printOne함수를 호출
}


