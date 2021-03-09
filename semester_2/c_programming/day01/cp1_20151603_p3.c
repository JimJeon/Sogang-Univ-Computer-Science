#include<stdio.h>
#include<math.h>

int main(void){
	double a,b,c,d;
	double *pa=&a,*pb=&b,*pc=&c,*pd=&d;

	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);

	printf("%lf\n",sqrt((*pa-*pc)*(*pa-*pc)+(*pb-*pd)*(*pb-*pd)));

	return 0;
}

