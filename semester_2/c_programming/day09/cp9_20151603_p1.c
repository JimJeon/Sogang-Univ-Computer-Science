#include<stdio.h>

int string_length(char *st);

int main(void){
	char s[] = "C is a high-level language";
	char *t = "C프로그래밍";

	printf(" 문자열 s의 길이 : %d\n",string_length(s));
	printf(" sizeof(s)		 : %d\n",(int)sizeof(s));
	printf(" 문자열 t의 길이 : %d\n",string_length(t));
	printf(" sizeof(t)		 : %d\n",(int)sizeof(t));

	return 0;
}

int string_length(char *st){
	int count = 0;
	while(*st != '\0'){
		count++;
		st++;
	}
	return count;
}

/*
 * s의 문자열의 길이는 "C is a high-level language"에서 띄어쓰기 포함 26글자이다.
 * 하지만 sizeof(s)의 값이 27이 나오는 이유는 문자열 마지막에 '\0', 즉 NULL문자가 포함되기 때문이다.
 * t의 문자열 길이는 겉보기에 "C프로그래밍"에서 6글자가 나와야 할 것 같지만
 * 한글은 ASCII를 사용하지 않고 UTF를 사용한다.
 * 따라서 ASCII처럼 한 글자를 1 바이트로 받아들이지 않기 때문에 문자열의 길이가 생각과 다르게 나온 것이다.
 * 또한 sizeof(t)의 값이 "c프로그래밍" + '\0' 해서 7이 나오지 않고 8이 나오는 이유도
 * 한글이 UTF를 사용하기 때문이다.
 */
