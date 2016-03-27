#include<stdio.h>
#include<math.h>
// char형 array를 double로 바꾸는 함수이다.
// 인자로는 char형 배열을 받는다.
double char2double(char num[]){
	double result = 0;
	int i, digit=0;
	for(i=0;i<10;++i){
		// '.'를 만나면 자릿수를 뒤로 밀고 digit을 0으로 초기화한다.
		if(num[i] == '.'){
			result /= pow(10,digit);
			digit =0;
		}
		// 차례차례 자리에 맞는 10의 거듭제곱을 곱해서 결과값에 더한다.
		if('0'<=num[i]&&num[i]<='9'){
			result += (num[i]-'0')*pow(10,digit);
			digit++;
		}
	}
	if(num[9] == '-')
		return -result;
	return result;
}

int main(void){
	char numInput[10];
	double numOutput;
	int i;
	printf("Input : ");
	for(i=9;i>0;--i){
		scanf("%c",&numInput[i]);
		if(numInput[i] == '\n')
			break;
	}
	numOutput = char2double(numInput);
	printf("Result: %f\n",numOutput);

	return 0;
}
