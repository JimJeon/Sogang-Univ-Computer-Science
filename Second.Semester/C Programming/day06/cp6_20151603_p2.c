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
void all_sort(int a[][100],int n,int m){
	while(n--)
		sort(a[n],m);
	return;
}
int binary_search(int *a,int* endPtr,int key,int **findPtr){
	int *strPtr = a;
	int *midPtr;
	do{
		midPtr = endPtr - (endPtr - strPtr)/2;
		if(*midPtr == key){
			*findPtr = midPtr;
			return 1;
		}
		if(*midPtr < key)
			strPtr = midPtr;
		if(*midPtr > key)
			endPtr = midPtr;
		
	}while(strPtr != endPtr);
	return 0;

}
int all_binary_search(int a[][100],int n,int m,int key,int **findPtr){
	int i;
	for(i=0;i<n;++i)
		if(binary_search(a[i],a[i]+m-1,key,findPtr))
			return 1;
	return 0;
}
int main(void){
	int n,m;
	int i,j;
	int user_input[100][100];
	int key;
	int *findPtr;
	int check;
	
	scanf("%d%d%d",&n,&m,&key);

	for(i=0;i<n;++i)
		for(j=0;j<m;++j)
			scanf("%d",&user_input[i][j]);
	all_sort(user_input,n,m);
	check = all_binary_search(user_input,n,m,key,&findPtr);
	if(check)
		printf("%d\n%p\n",check,findPtr);
	else
		printf("%d\n",check);
	return 0;
}
