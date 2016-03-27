#include <stdio.h>
// Global
int x=0;
int Fibonacci (int *y); // 피보나치 함수이다.
int main(){
	int x=1;
	printf("Fibo(2): %d\n",Fibonacci(&x));
	printf("Fibo(3): %d\n",Fibonacci(&x));
	printf("Fibo(4): %d\n",Fibonacci(&x));
	printf("Fibo(5): %d\n",Fibonacci(&x));
	printf("Fibo(6): %d\n",Fibonacci(&x));
	printf("Fibo(7): %d\n",Fibonacci(&x));
	printf("Fibo(8): %d\n",Fibonacci(&x));
	printf("Fibo(9): %d\n",Fibonacci(&x));
	return 0;
}
// 전역변수는 n-2번째, 인자는 n-1번째로 받아 n번째 피보나치 값을 출력한다.
// 이 때, n은 함수의 호출 회수 + 1 이다.
int Fibonacci (int*y){
	int fibo;
	fibo = x+*y;
	x=*y;
	*y=fibo;
	return fibo;
}

