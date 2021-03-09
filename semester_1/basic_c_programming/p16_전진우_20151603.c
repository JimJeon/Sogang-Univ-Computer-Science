#include<stdio.h>
int main(void){
	int number1,number2,carry_cnt=0;
	printf("Enter 2 numbers: ");
	scanf("%d %d",&number1,&number2);
	if (number1%10+number2%10>=10) carry_cnt++;
	if ((number1/10)%10+(number2/10)%10+carry_cnt>=10){
		carry_cnt++;
		if(number1/100+number2/100+1>=10) carry_cnt++;
	}
	else{
		if (number1/100+number2/100>=10) carry_cnt++;
	}
	
	printf("%d carry operations\n",carry_cnt);
	return 0;
}
