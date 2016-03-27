#include<stdio.h>
int a,b;
void fourmath (int*,int*); // 사칙연산 함수
void printResult(int*,int*); // 출력 함수
int main(){
	int a,b;
	printf("Input two number : ");scanf("%d %d",&a,&b);
	fourmath(&a,&b);
	printResult(&a,&b);
	return 0;
}
// 사칙연산을 수행한 뒤 이용가능한 변수에 값을 저장한다.
// 두 인자는 main에서 선언된 지역변수의 주소값을 받는다.
void fourmath(int*c,int*d){
	a = *c + *d; // 전역변수 a를 이용.
	b = *c - *d; // 전역변수 b를 이용.
	*c = *c * *d; // 지역변수 *c를 이용.
	*d = (*c / *d) / *d; // 지역변수 *d를 이용. 변경된 *c의 값을 고려한 계산을 수행한다.
}
// 사칙연산의 결과를 출력하는 함수이다.
// 두 인자는 결과 값이 저장된 지역변수의 주소값을 받는다.
void printResult(int*c,int*d){
	printf("Result : a+b=%d, a-b=%d, a*b=%d, a/b=%d\n",a,b,*c,*d);
}

	
