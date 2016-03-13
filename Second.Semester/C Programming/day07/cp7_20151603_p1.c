#include<stdio.h>
#include<stdlib.h>

int *get_new_array(int size);
void get_new_array_call_by_value(int *a,int size);
void get_new_array_call_by_reference(int **a,int size);
void print_state(int *a);

int main(void){
	int *a = NULL;
	print_state(a);

	get_new_array_call_by_value(a,10);
	print_state(a);
	free(a);

	get_new_array_call_by_reference(&a,10);
	print_state(a);
	free(a);

	a = get_new_array(10);
	print_state(a);
	free(a);
	return 0;
}

int *get_new_array(int size){
	int* newArray = (int*)malloc(sizeof(int)*size);
	return newArray;
}
void get_new_array_call_by_value(int *a,int size){
	a = (int*)malloc(sizeof(int)*size);
}
void get_new_array_call_by_reference(int **a,int size){
	*a = (int*)malloc(sizeof(int)*size);
}
void print_state(int *a){
	if(!a)
		printf("not allocated\n");
	else
		printf("allocated\n");
}

/* get_new_array_call_by_value 함수를 분석하여 보자.
 * 먼저 그 인자를 살펴보면 int *a,int size로 인트형 포인터와 사이즈의 값을 인자로 받는다.
 * 여기서 인트형 포인터를 인자로 받는다는 것은 즉, 인트형 주소값을 복사하여 그 값만을 가져온다는 것이다.
 * 따라서 함수 내부에서 a라는 변수에 새로운 주소를 만들어 할당하여 주어도
 * a는 함수 내부 변수이므로 함수가 종료됨과 동시에 바뀐 주소를 잃어버린다.
 *
 * 반면에 get_new_array_call_by_reference 함수에서는 더블 포인터, 즉 주소값의 주소를 인자로 받기 때문에
 * 함수가 종료되어도 a의 바뀐 주소값이 남아있게 되는것이다.
 */
