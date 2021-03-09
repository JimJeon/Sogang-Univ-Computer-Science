#include <stdio.h>
float average(int,int,int,int); // 평균함수
float deviation(float,int); // 편차함수
int main()
{
	// Declaration and Input
	int number1,number2,number3,number4;
	float ave,dev;
	printf("Enter the first number : ");
	scanf("%d",&number1);
	printf("Enter the second number : ");
	scanf("%d",&number2);
	printf("Enter the third number : ");
	scanf("%d",&number3);
	printf("Enter the fourth number : ");
	scanf("%d",&number4);
	//Excute and Output
	ave = average(number1,number2,number3,number4);
	printf("******** average is %6.2f ********\n",ave);
	dev = deviation(ave,number1);
	printf("first number :\t\t%6d  -- deviation :%20.2f\n",number1,dev);
	dev = deviation(ave,number2);
	printf("second number :\t\t%6d  -- deviation :%20.2f\n",number2,dev);
	dev = deviation(ave,number3);
	printf("third number :\t\t%6d  -- deviation :%20.2f\n",number3,dev);
	dev = deviation(ave,number4);
	printf("fourth number :\t\t%6d  -- deviation :%20.2f\n",number4,dev);
	return 0;
}

// 평균을 구하는 함수이다.
// 네개의 인자는 평균을 구할 수 4개이다.
float average(int a,int b,int c,int d)
{
	float result;
	result = (a+b+c+d)/4.0;
	return result;
}
// 편차를 구하는 함수이다.
// 첫번째 인자는 평균, 두번째 인자는 숫자이다.
float deviation(float ave,int num)
{
	float result;
	result = num - ave;
	return result;
}
