#include<stdio.h>
int check(char binary[]){
	int i;
	for(i=0;i<100;++i){
		if(binary[i] == '\0') return 0;
		if(!(binary[i]=='1'||binary[i]=='0'))
			return 1;
	}
}
int biToDec(char binary[]){
	int i, decimal=0;
	for(i=0;binary[i]!='\0';++i)
		decimal = decimal*2 + binary[i] - '0';
	return decimal;
}
int main(void){
	char binary[100];
	
	printf("Enter binary number : ");
	scanf("%s",binary);
	if(check(binary)){
		printf("Invalid binary number\n");
		return 1;
	}
	
	printf("Decimal number : %d\n",biToDec(binary));

	return 0;
}


