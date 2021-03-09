#include <stdio.h>

int main(){
	// Declaration and Input
	float number;
	printf("Input : ");
	scanf("%f",&number);

	// Output
	// Input에 0.5를 더해서 형변환해 Input과 다시 비교한다.
	printf("Use \">\" : %d\n",(int)(number+0.5)>(int)number);
	// 형변환을 이용하여 Input의 소수부를 구해 비교한다.
	printf("Use \">=\" : %d\n",(number-(int)number) >= 0.5);
	// Input에 0.5를 더해서 형변환해 Input+1과 다시 비교한다.
	printf("Use \"==\" : %d\n",(int)(number+0.5)==(int)number+1);
	// Input에 0.5를 더해서 형변환해 Input과 다시 비교한다.
	printf("Use \"!=\" : %d\n",(int)(number+0.5)!=(int)number);

	return 0;
}

