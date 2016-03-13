#include<stdio.h>

void shift_left(int *a){
	int tmp;
	int i = 9;

	tmp = *a;
	while(i--){
		*a = *(a+1);
		a += 1;
	}

	*a = tmp;
}
void shift_n_left(int *a,int n){
	while(n--)
		shift_left(a);
}
void print_array(int *a){
	int i;
	for(i=0;i<10;++i)
		printf("%d ",*(a+i));
	printf("\n");
}
int main(void){
	int b =9999;
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int n;

	scanf("%d",&n);
	
	shift_n_left(a,n);

	print_array(a);

	return 0;
}
