#include <stdio.h>

int Sumfunc(int,int);

int main()
{
	// Declaration
	int number1,number2,Result;

	// Input
	printf("Input first number : ");
	scanf("%d",&number1);
	printf("Input second number : ");
	scanf("%d",&number2);
	
	// Excute
	Result = Sumfunc(number1,number2);
	
	// Output
	printf("%d + %d = %d\n",number1,number2,Result);
	
	return 0;

}

// 받은 두 인자를 더한 뒤 그 결과 값을 반환하는 함수이다.
// 더하고 싶은 두 정수 인자를 받는다.
int Sumfunc(int num1,int num2)
{
	int Result;
	Result = num1+num2; // 인자를 더함
	return Result; // 결과를 반환
}
