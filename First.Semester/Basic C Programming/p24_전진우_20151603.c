#include<stdio.h>
int Fibonacci(int); // 피보나치 함수
int main(void){
	int number;
	printf("Input n: "); scanf("%d",&number);
	if (number<0) printf("n cannot be negative number.\n"); // 음수 값을 입력했을 때 예외처리한다.
	else printf("fib(%d) = %d\n",number,Fibonacci(number));
	return 0;
}
// number번째 피보나치 값을 반환하는 함수이다.
// 인자로 number를 받고 그 값에 따라 피보나치 함수를 실행한다.
int Fibonacci(int number){
	int current=-1,prev=1;
	do{
		current = current + prev;
		prev = current - prev;
	}while(number--); // number가 0이 되면 loop 을 탈출한다.
	return -current;
}
