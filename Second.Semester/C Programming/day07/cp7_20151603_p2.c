#include<stdio.h>
#include<stdlib.h>

int *get_next_process(int *prev_pointer,int size);

int main(void){
	int size;
	int* candy_box;
	int i;

	scanf("%d",&size);
	candy_box = (int*)malloc(sizeof(int)*size);
	
	for(i=size;i>0;--i)
		scanf("%d",candy_box+i-1);


	while(size!=1){
		candy_box = get_next_process(candy_box,size);
		size = (size+1)/2;

		for(i=0;i<size;++i)
			printf("%d ",candy_box[i]);
		puts("");
	}
	free(candy_box);

	return 0;
}
int *get_next_process(int *prev_pointer,int size){
	int next_size;
	int* next_pointer;
	int i,j;
	next_size = (size+1)/2;
	next_pointer = (int*)malloc(sizeof(int)*next_size);
	for(i=0;i<size;++i){
			next_pointer[i/2] += prev_pointer[i];
	}
	free(prev_pointer);
	return next_pointer;
}
