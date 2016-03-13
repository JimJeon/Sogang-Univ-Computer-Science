#include<stdio.h>

void HotelFunc(int Hotel[9][99],int width,int height,int number){
	int i,j;
	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			*(*(Hotel+j)+i) = --number;
			if(number == 0) return;
		}
	}
	return;
}

int main(void){
	int height, width, number;
	int Hotel[9][99] = {0,};
	int i,j;

	scanf("%d%d%d",&height,&width,&number);
	HotelFunc(Hotel,width,height,number);
	for(i=0;i<width;++i){
		for(j=0;j<height;++j){
			if(*(*(Hotel+j)+i) == 0){
				printf("%d%02d\n",j+1,i+1);
				return 0;
			}
		}
	}
}
