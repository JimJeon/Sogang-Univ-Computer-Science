#include<stdio.h>
// from부터 끝까지 중에서 가장 작은 값의 인덱스를 반환하는 함수이다.
// 인자로는 data배열과 시작 인덱스 from을 받는다.
int minIndex(int data[10],int from){
	int min = data[from];
	int Index = from;
	int i;

	for(i=from;i<10;++i){
		if(min>data[i]){
			min = data[i];
			Index = i;
		}
	}
	return Index;
}
// 배열의 두 값을 바꾸는 함수이다.
// 인자로는 data배열과 바꿀 두 인덱스를 받는다.
void swap(int data[10],int i,int j){
	int tmp;
	tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
}
int main(void){
	int data[10];
	int i;
	printf("Input : ");
	for(i=0;i<10;++i) scanf("%d",&data[i]);
	for(i=0;i<10;++i) swap(data,i,minIndex(data,i));
	printf("Sorting : ");
	for(i=0;i<10;++i) printf("%d ",data[i]);
	printf("\n");
	return 0;
}

