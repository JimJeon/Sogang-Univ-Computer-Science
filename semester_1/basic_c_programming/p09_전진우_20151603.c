#include <stdio.h>
void divideRemainder(int*,int*); // 몫과 나머지를 구하는 함수
int main(){
	int a,b;
	printf("Input two Number : ");
	scanf("%d %d",&a,&b);
	printf("----------------------------------------\n");
	divideRemainder(&a,&b);
	printf("OUTPUT : divide [%d] remainder [%d]\n",a,b);
	return 0;
}
// 두 정수를 입력받아 몫과 나머지를 계산한다.
// 두 정수 변수의 주소값을 인수로 받는다.
void divideRemainder(int*a,int*b){
	int temp;
	temp = *a / *b;
	*b = *a%*b;
	*a = temp;
}

