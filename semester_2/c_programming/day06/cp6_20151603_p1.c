#include<stdio.h>

void swap(int* a,int* b){
	int tmp = *a;
	if(*a>*b){
		*a = *b;
		*b = tmp;
	}
	return;
}
void sort(int *a,int m){
	int i;
	while(m--)
		for(i=0;i<m;++i)
			swap(&a[i],&a[i+1]);
	return;
}
void print_array(int *a,int m){
	int i;
	for(i=0;i<m;++i)
		printf("%d ",a[i]);
	puts("");
	return;
}
void all_sort(int a[][100],int n,int m){
	while(n--)	
		sort(a[n],m);
	return;
}
void print_all_array(int a[][100],int n,int m){
	int i;
	for(i=0;i<n;++i)
		print_array(a[i],m);
	return;
}
int main(void){
	int n,m;
	int i,j;
	int user_input[100][100];
	
	scanf("%d%d",&n,&m);

	for(i=0;i<n;++i)
		for(j=0;j<m;++j)
			scanf("%d",&user_input[i][j]);
	all_sort(user_input,n,m);
	print_all_array(user_input,n,m);
	return 0;
}
