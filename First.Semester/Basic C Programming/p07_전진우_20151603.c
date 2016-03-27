#include <stdio.h>
float Calc_x(int, int, int, int); // x값 함수
float Calc_y(float,int,int); // y값 함수

int main()
{
	// Declaration
	int coe_a, coe_b, coe_c, coe_d;
	float result_x,result_y;
	// Input
	printf("1st equation : y = ax - b, input 'a' and 'b'\n");
	printf("a = ");
	scanf("%d",&coe_a);
	printf("b = ");
	scanf("%d",&coe_b);
	printf("2nd equation : y = cx - d, input 'c' and 'd'\n");
	printf("c = ");
	scanf("%d",&coe_c);
	printf("d = ");
	scanf("%d",&coe_d);
	// Excute
	result_x = Calc_x(coe_a,coe_b,coe_c,coe_d);
	result_y = Calc_y(result_x,coe_a,coe_b);
	// Output
	printf("result : \nx is %.6f\ny is %.6f\n",result_x,result_y);
	return 0;
}

// x의 값을 구하는 함수이다.
// 연립방정식을 풀기 위해 각 식의 계수들 a,b,c,d를 받는다.
float Calc_x(int a,int b, int c, int d)
{
	float result;
	result = (float)(b-d)/(float)(a-c); // 식을 정리하여 얻은 x = (b-d)/(a-c)를 이용하여 x의 값을 구한다.
	return result;

}
// y의 값을 구하는 함수이다.
// x,a,b는 식 y=ax-b를 구현하기 위한 인자들이다.
float Calc_y(float x,int a, int b)
{
	float result;
	result = a*x-b;  // x의 값을 입력하면 주어진 식 y=ax-b에 대입하여 y값을 구한다.
	return result;
}
