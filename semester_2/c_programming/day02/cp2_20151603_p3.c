#include<stdio.h>
void f(int *H,int *M,int* S,int T){
	*M += (*S + T)/60;
	*H += *M/60;
	*M %= 60;
	*H %= 24;
	*S = (*S + T)%60;
}

int main(void){
	int H,M,S,T;

	scanf("%d%d%d%d",&H,&M,&S,&T);
	f(&H,&M,&S,T);
	printf("%02d:%02d:%02d\n",H,M,S);
	return 0;
}
