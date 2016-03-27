#include<stdio.h>
float addition(float,float); // 더하기
float subtraction(float,float); // 빼기
float multiplication(float,float); // 곱하기
float division(float,float); // 나누기
int main(){
	float operand1,operand2;
	char operatorx;
	printf("Operator (+, -, *, /)\n");
	printf("Please enter the formula. (ex : 12.3 + 5.5)\n");
	scanf("%f %c %f",&operand1,&operatorx,&operand2);
	// 연산자 판단에 ASCII코드를 이용했다.
	switch(operatorx){
	case 43: printf("%.2f + %.2f = %.2f\n",operand1,operand2,addition(operand1,operand2)); break;
	case 45: printf("%.2f - %.2f = %.2f\n",operand1,operand2,subtraction(operand1,operand2)); break;
	case 42: printf("%.2f * %.2f = %.2f\n",operand1,operand2,multiplication(operand1,operand2)); break;
	case 47:
		// 0으로 나누기 에러
		if(operand2==0) printf("Division by zero\n");
		else printf("%.2f / %.2f = %.2f\n",operand1,operand2,division(operand1,operand2));
		break;
	// 알수 없는 연산자
	default: printf("Invalid operator : %c\n",operatorx);
	}
	return 0;
}
// 더하기 구현 함수이다.
// 두 실수 인자값을 받아 더해서 반환한다.
float addition(float number1,float number2){
	return number1+number2;
}
// 빼기 구현 함수이다.
// 두 실수 인자값을 받아 빼서 반환한다.
float subtraction(float number1,float number2){
	return number1-number2;
}
// 곱하기 구현 함수이다.
// 두 실수 인자값을 받아 곱해서 반환한다.
float multiplication(float number1,float number2){
	return number1*number2;
}
// 나누기 구현 함수이다.
// 두 실수 인자값을 받아 나눠서 반환한다.
float division(float number1,float number2){
	return number1/number2;
}
