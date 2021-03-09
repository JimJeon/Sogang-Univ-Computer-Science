#include<stdio.h>
void swap(int*, int*); // SWAP 함수
void func_gcd(int a,int b,int* gcd); // 최대공약수 함수
int main(void){
	// Declaration and Input
	int first_num,second_num;
	int greatest_common_divisor;
	printf("Input first number : "); scanf("%d",&first_num);
	printf("Input second number : "); scanf("%d",&second_num);
	// Function Call
	func_gcd(first_num, second_num, &greatest_common_divisor);
	// Output
	printf("GCD: %d\n",greatest_common_divisor);
	return 0;
}
// 두 변수의 값을 바꾼다.
// 두 변수의 주소값을 인자로 받는다.
void swap(int* a,int* b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
// while loop을 이용하여 최대공약수를 구하며 그 과정을 출력한다.
// 인자는 최대공약수를 구할 두 수와 최대공약수를 대입할 변수의 주소값을 받는다.
void func_gcd(int a,int b,int* gcd){
	int remainder=1;
	if(a<b) swap(&a,&b);
	// remainder가 0이 될 때까지 loop을 돈다.
	while (remainder){
		printf("%d = %d X %d + %d\n",a,b,a/b,a%b);
		remainder = a%b;
		a = b;
		b = remainder;
	}
	*gcd = a;
}		
