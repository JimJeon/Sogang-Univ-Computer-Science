#include<stdio.h>

void *f(void *pa,void *pb,int option){
	switch(option){
		case 0: if(*(int*)pa>*(int*)pb) return pb;
				else return pa;
				break;
		case 1: if(*(float*)pa>*(float*)pb) return pb;
				else return pa;
				break;
		case 2: if(*(double*)pa>*(double*)pb) return pb;
				else return pa;
				break;
	}
}

int main(void){
	int option;
	int a,b;
	float fa,fb;
	double da,db;
	void *pa,*pb,*ans;

	scanf("%d",&option);
	switch(option){
		case 0: scanf("%d%d",&a,&b);
				ans = f(&a,&b,option);
				printf("%d\n",*(int*)ans);
				break;
		case 1:	scanf("%f%f",&fa,&fb);
				ans = f(&fa,&fb,option);
				printf("%0f\n",*(float*)ans);
				break;
		case 2: scanf("%lf%lf",&da,&db);
				ans = f(&da,&db,option);
				printf("%0lf\n",*(double*)ans);
				break;
	}
	return 0;
}
