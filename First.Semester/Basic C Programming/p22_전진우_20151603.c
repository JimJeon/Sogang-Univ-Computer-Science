#include<stdio.h>
void swap(int*,int*); // SWAP 함수
int two_three_sum(int,int); // 합 함수
int main(void){
	// Declaration
	int first_num,second_num;
	printf("Input first number: ");scanf("%d",&first_num);
	printf("Input second number: ");scanf("%d",&second_num);
	// Error Message
	if (first_num<1||second_num<1){
		printf("Input is less than 1\n");
		return 0;
	}
	// Sorting
	if (first_num>second_num) swap(&first_num,&second_num);
	// Output
	printf("Result: %d\n",two_three_sum(first_num,second_num));
	return 0;
}
// 두 변수의 값을 교체한다.
// 두 인자는 각각 변수의 주소값을 받는다.
void swap(int* a,int* b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
// 상한과 하한을 받아 그 안의 2의 배수와 3의 배수를 모두 더한다.
// 두 인자는 상한과 하한을 받는다.
int two_three_sum(int min,int max){
	int loop,result=0;
	for(loop=min;loop<=max;loop++) if (loop%2==0||loop%3==0) result += loop;
	return result;
}
