#include<stdio.h>
void leap_check(int); // 윤년 검사 함수
void closest_leap(int); // 가까운 윤년 함수
int main(){
	int year;
	printf("Enter the year to be tested: ");
	scanf("%d",&year);
	leap_check(year);
	return 0;
}
// 윤년인지 검사하여 윤년이면 출력, 윤년이 아니면 출력하고 closest_leap함수를 호출한다.
// 입력받은 년도를 인자로 받는다.
void leap_check(int year){
	if ((year%4==0)&&(year%100!=0)) printf("%d is a leap year.\n",year);
	else{
		if (year%400==0) printf("%d is a leap year.\n",year);
		else {
			printf("%d is not a leap year.\n",year);
			closest_leap(year);
		}
	}
}
// 입력받은 년도에서 가장 가까운 윤년을 계산하여 출력한다.
// 입력받은 년도를 인자로 받는다.
void closest_leap(int year){
	year-= (year%4);
	if ((year%100==0)&&(year%400!=0))year-=4;
	printf("%d is a leap year.\n",year);
}
