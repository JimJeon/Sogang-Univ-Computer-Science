#include<stdio.h>
// 점화식을 구현하는 함수
// 인자로 정수 n을 받는다.
int function (int n){
	if (n==1) return 1;
	else return 2*function(n-1)+1;
}
int main(void){
	int number;
	printf("Input : "); scanf("%d",&number);
	printf("%d 번째 항 : %d\n",number,function(number));
	return 0;
}
