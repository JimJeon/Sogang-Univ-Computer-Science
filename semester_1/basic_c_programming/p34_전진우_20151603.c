#include<stdio.h>
// n!의 값을 구하는 함수이다.
// 인자로는 n 즉, number를 받는다.
int factorial(int number){
	if(number == 0) return 1;
	return factorial(number-1) * number;
}
// 오일러 수의 값을 reculsive로 구한다.
// 인자로는 number를 받는다.
// 오일러 수 e = 1/0! + 1/1! + ... + 1/n!
double getEuler(int number){
	if(0.0000001>1.0/factorial(number)) return 1.0/factorial(number);
	return 1.0/factorial(number) + getEuler(number+1);
}
int main(void){
	double EulerNumber;
	printf("approximate euler's number : %.8f\n",getEuler(0));
	return 0;	
}
