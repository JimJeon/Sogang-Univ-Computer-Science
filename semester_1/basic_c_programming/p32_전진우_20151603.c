#include<stdio.h>
int main(void){
	FILE* fp;
	char name[21];
	int grade;

	fp = fopen("basic.txt","w");
	if(fp == NULL){
		printf("file open error!\n");
		return 1;
	}
	printf("Input name and grade:\n");
	scanf("%s %d",name,&grade);
	fprintf(fp,"Grade of %s is %d.\n",name,grade);
	fclose(fp);
	return 0;
}

