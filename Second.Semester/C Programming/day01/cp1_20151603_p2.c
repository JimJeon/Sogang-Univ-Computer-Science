#include<stdio.h>

int main(void){
	double a,b,c,d;
	double *pa=&a,*pb=&b,*pc=&c,*pd=&d;

	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	if(*pa == *pc){
		if(*pb == *pd) printf("oo\n");
		else printf("%d\n",0);
	}
	else printf("%d\n",1);

	return 0;
}
