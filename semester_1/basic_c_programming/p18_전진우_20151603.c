#include<stdio.h>
float addition(float,float); // ���ϱ�
float subtraction(float,float); // ����
float multiplication(float,float); // ���ϱ�
float division(float,float); // ������
int main(){
	float operand1,operand2;
	char operatorx;
	printf("Operator (+, -, *, /)\n");
	printf("Please enter the formula. (ex : 12.3 + 5.5)\n");
	scanf("%f %c %f",&operand1,&operatorx,&operand2);
	// ������ �Ǵܿ� ASCII�ڵ带 �̿��ߴ�.
	switch(operatorx){
	case 43: printf("%.2f + %.2f = %.2f\n",operand1,operand2,addition(operand1,operand2)); break;
	case 45: printf("%.2f - %.2f = %.2f\n",operand1,operand2,subtraction(operand1,operand2)); break;
	case 42: printf("%.2f * %.2f = %.2f\n",operand1,operand2,multiplication(operand1,operand2)); break;
	case 47:
		// 0���� ������ ����
		if(operand2==0) printf("Division by zero\n");
		else printf("%.2f / %.2f = %.2f\n",operand1,operand2,division(operand1,operand2));
		break;
	// �˼� ���� ������
	default: printf("Invalid operator : %c\n",operatorx);
	}
	return 0;
}
// ���ϱ� ���� �Լ��̴�.
// �� �Ǽ� ���ڰ��� �޾� ���ؼ� ��ȯ�Ѵ�.
float addition(float number1,float number2){
	return number1+number2;
}
// ���� ���� �Լ��̴�.
// �� �Ǽ� ���ڰ��� �޾� ���� ��ȯ�Ѵ�.
float subtraction(float number1,float number2){
	return number1-number2;
}
// ���ϱ� ���� �Լ��̴�.
// �� �Ǽ� ���ڰ��� �޾� ���ؼ� ��ȯ�Ѵ�.
float multiplication(float number1,float number2){
	return number1*number2;
}
// ������ ���� �Լ��̴�.
// �� �Ǽ� ���ڰ��� �޾� ������ ��ȯ�Ѵ�.
float division(float number1,float number2){
	return number1/number2;
}
