#include<stdio.h>
// 입력받은 숫자가 palindrome인지 판별하는 재귀적 함수.
// num은 입력받은 숫자이며 digit은 현재 palindrome을 판별하고 있는 자릿수이다.
int palindrome (int num, int digit){
	int length=1;
	if (num==0) return 1;
	do{
		if(num/(length*10) == 0) break;
	} while(length*=10);
	if(digit>length/digit) return 1;
	if((num%(digit*10)/digit) == (num/(length/digit)%10)) {
		return palindrome(num,digit*10);
	}
	else return 0;
}
int main(void){
	int number;
	printf("Input: "); scanf("%d",&number);
	if(number<0) printf("Input number cannot be negative.\n");
	else{
		if(palindrome(number,1)) printf("%d is a palindrome number.\n",number);
		else printf("%d is not a palindrome number.\n",number);
	}
	return 0;
}
