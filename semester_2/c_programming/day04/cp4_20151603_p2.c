#include<stdio.h>

void swap(int *a,int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void sort(int *a,int n){
	int i;
	while(n--)
		for(i=0;i<n;++i)
			if(*(a+i)>*(a+i+1))
				swap(a+i,a+i+1);
}
void print_array(int *a,int n){
	int i;
	for(i=0;i<n;++i)
		printf("%d ",*(a+i));
	printf("\n");
}

int main(void){
	int n;
	int user_input[1000];
	int i;

	scanf("%d",&n);
	
	for(i=0;i<n;++i)
		scanf("%d",user_input+i);

	sort(user_input,n);

	print_array(user_input,n);

	return 0;
}
