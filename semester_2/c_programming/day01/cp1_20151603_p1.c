#include<stdio.h>

int main(void){
	int a,b;
	int *pa=&a, *pb=&b, *pt;

	scanf("%d%d",&a,&b);

	if(a>b){
		*pt = *pa;
		*pa = *pb;
		*pb = *pt;
	}

	printf("%d %d\n%p %p\n",*pa,*pb,pa,pb);

	return 0;
}
