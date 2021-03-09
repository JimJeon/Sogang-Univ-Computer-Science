#include<stdio.h>
#include<math.h>
void sort(int*,int*); // 정렬함수
int main(void){
	int number1,number2,number3,number4,number5;
	printf("Please input 5 integers : ");
	scanf("%d %d %d %d %d",&number1,&number2,&number3,&number4,&number5);
	sort(&number1,&number2);
	sort(&number2,&number3);
	sort(&number3,&number4);
	sort(&number4,&number5);
	sort(&number1,&number2);
	sort(&number2,&number3);
	sort(&number3,&number4);
	sort(&number1,&number2);
	sort(&number2,&number3);
	sort(&number1,&number2);
	printf("%d %d %d %d %d\n",number1,number2,number3,number4,number5);
	return 0;
}
// 두 수를 입력 받아서 첫번째 인자에 작은 수, 두번째 인자에 큰 수를 반환한다.
// Call by reference 방식으로 두 인트형의 주소값을 인자로 받는다.
void sort(int* number1,int* number2){
	float average,diff;
	average = (*number1+*number2)/2.0;
	diff = fabs(average-*number1);
	*number1 = average - diff;
	*number2 = average + diff;
}
