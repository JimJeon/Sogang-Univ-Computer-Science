#include<stdio.h>
int isDivisor(int m,int n); // 약수 확인 함수
int isPrime(int m); // 소수 확인 함수
int main(void){
	int number;
	int i;
	printf("Input : "); scanf("%d",&number);
	for(i=1;i<=number;++i) if(isDivisor(i,number)) if(isPrime(i)) printf("%d\t",i);
	printf("\n");
	return 0;
}
// m이 n의 약수이면 1을 반환하고 아니면 0을 반환한다.
// n이 본래의 수, m이 약수인지 확인하는 수이다.
int isDivisor(int m,int n){
	if(n%m==0) return 1;
	else return 0;
}
// m이 소수이면 1을 아니면 0을 반환한다.
// 소수인지 확인할 m을 인자로 받는다.
int isPrime(int m){
	int i,flag=0;
	if (m==1) return 0; // 1은 소수의 조건을 만족하지만 소수가 아니므로 예외처리한다.
	else for(i=1;i<m;++i) if (m%i==0) flag++;
	if (flag==1) return 1;
	else return 0;
}
