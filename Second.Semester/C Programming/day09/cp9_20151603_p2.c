#include<stdio.h>
#include<stdlib.h>

void upper_to_lower(char *s);
void lower_to_upper(char *s);

int main(void){
	char test[1000] = "There is no Free Lunch";

	upper_to_lower(test);
	printf("%s\n",test);
	lower_to_upper(test);
	printf("%s\n",test);

	return 0;
}

void upper_to_lower(char *s){
	while(*s != '\0'){
		if(64<*s&&*s<91)
			*s+=32;
		s++;
	}

	return;
}
void lower_to_upper(char *s){
	while(*s != '\0'){
		if(96<*s&&*s<123)
			*s-=32;
		s++;
	}

	return;
}
