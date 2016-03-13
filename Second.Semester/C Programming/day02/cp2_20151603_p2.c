#include<stdio.h>

void swap(int *a,int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int* f(int* a,int* b,int* c){
	if(*a>*b) swap(a,b);
	if(*b>*c) swap(b,c);
	if(*a>*b) swap(a,b);

	return b;
}
int main(void){
	int a,b,c,mid;

	scanf("%d%d%d",&a,&b,&c);
	mid = *f(&a,&b,&c);
	printf("%d\n%d %d %d\n",mid,a,b,c);

	return 0;
}

