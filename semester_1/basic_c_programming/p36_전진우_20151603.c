#include<stdio.h>
void mergeArray(int arrayA[],int arrayB[],int mergedArray[]){
	int cntA=0,cntB=0,i;
	for(i=0;i<10;++i){
		if(cntA>=5){
			mergedArray[i] = arrayB[cntB++];
			continue;
		}
		else if(cntB>=5){
			mergedArray[i] = arrayA[cntA++];
			continue;
		}
		else if(arrayA[cntA] > arrayB[cntB]){
			mergedArray[i] = arrayB[cntB++];
			continue;
		}
		else if(arrayB[cntB] >= arrayA[cntA]){
			mergedArray[i] = arrayA[cntA++];
			continue;
		}
	}
}
int main(void){
	int arrayA[5] = {0,};
	int arrayB[5] = {0,};
	int mergedArray[10] = {0,};
	int i;
	printf("Input arrayA: ");
	for(i=0;i<5;++i) scanf("%d",&arrayA[i]);
	printf("Input arrayB: ");
	for(i=0;i<5;++i) scanf("%d",&arrayB[i]);

	mergeArray(arrayA,arrayB,mergedArray);
	
	printf("Merged Array: ");
	for(i=0;i<10;++i) printf("%d ",mergedArray[i]);
	printf("\n");
	return 0;
}
