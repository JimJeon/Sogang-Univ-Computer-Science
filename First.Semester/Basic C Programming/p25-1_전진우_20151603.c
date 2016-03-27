#include<stdio.h>
void check_correct(int,int,int); // 정답 체크 함수
int main(void){
	int number;
	printf("Enter the correct : ");
	scanf("%d",&number);
	check_correct(number/100,(number/10)%10,number%10);
	return 0;
}
// 사용자가 입력한 숫자가 정답과 같은지 확인하는 함수
// 인자로는 정답의 각 자릿수를 받는다.
void check_correct(int ans_f,int ans_s,int ans_t){
	int strike,ball,trial=0;
	int number,att_f,att_s,att_t;
	// 사용자가 정답을 맞출때까지 계속 루프를 돈다.
	// 루프를 돌면서 trial에 시도 횟수를 계속 1씩 더한다.
	while(++trial){
		printf("Play Ball : ");
		scanf("%d",&number);
		att_f = number/100;
		att_s = (number/10)%10;
		att_t = number%10;
		if(att_f==att_s||att_f==att_t||att_s==att_t){
			printf("Invalid input\n");
			trial --;
			continue;
		}
		strike = 0; ball = 0;
		// 스트라이크의 경우의 수 3가지를 확인한다.
		strike += (ans_f == att_f);
		strike += (ans_s == att_s);
		strike += (ans_t == att_t);
		// 볼의 경우의 수 6가지를 확인한다.
		ball += (ans_f == att_s); ball += (ans_s == att_f); ball += (ans_t == att_f);
		ball += (ans_f == att_t); ball += (ans_s == att_t); ball += (ans_t == att_s);
		printf("%d Strike, %d Ball!\n",strike,ball);
		// 세 숫자 모두 스트라이크이면 성공함을 출력하고 루프를 탈출한다.
		if (strike == 3){
			printf("Sucess!\nTry count is %d\n",trial);
			break;
		}
	}
}
