#include<stdio.h>
// 글자가 소문자이면 대문자로 바꾸어준다.
// 인자는 입력받은 문자들의 배열을 받는다.
void Convert2Upper(char word[50]){
	int i;
	for(i=0;i<50;++i)
		if('a'<=word[i]&&'z'>=word[i])
			word[i] -= 'a'-'A';
}

int main(void){
	char word[50];
	int i;
	for(i=0;i<50;++i){
		scanf("%c",&word[i]);
		// Enter를 입력받으면 입력을 중단한다.
		if(word[i] == '\n') break;
	}
	Convert2Upper(word);
	for(i=0;i<50;++i){
		// Enter가 나오면 출력을 종료한다.
		if(word[i] == '\n') break;
		printf("%c",word[i]);
	}

	printf("\n");
	return 0;
}

	
