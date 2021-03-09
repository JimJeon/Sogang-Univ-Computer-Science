#include<stdio.h>

void swap(float*x,float*b); // 두 인자의 값을 바꾸는 함수.
int main(){
	float x,y;
	printf("Input two Number\n");
	printf("	x : ");scanf("%f",&x);
	printf("	y : ");scanf("%f",&y);
	printf("----------------------------------------\n");
	printf("Before : x [%d] y [%d]\n",(int)x,(int)y);
	swap(&x,&y);
	printf("----------------------------------------\n");
	printf("After  : x [%d] y [%d]\n",(int)x,(int)y);
	return 0;
}
// 두 인자의 값을 입력받아 temp 변수를 이용해 값을 바꾸는 함수이다.
// 두 인자는 각각 변수의 주소값을 받는 call by reference 형식이다.
void swap(float*x,float*y){
	float temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

	
