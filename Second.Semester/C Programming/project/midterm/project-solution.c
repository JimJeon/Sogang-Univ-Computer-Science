/*
 * using Backtracking
 * mobile computing & data engineering 
 * Sangkeun Kim
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef false
#define false 0
#endif
#ifndef true
#define true !(false)
#endif
int min(int a,int b) {return a<b?a:b;}
int max(int a,int b) {return a>b?a:b;}
int abs(int a) {return a>=0?a:-a;}
int* get_1d_new_array(int m) {
	int *ret = (int *)malloc(sizeof(int)*m);
	for ( int i = 0 ; i < m ; i++ ) 
		*(ret+i) = 0;
	return ret;
}
int** get_2d_new_array(int n,int m) {
	int **ret = (int **)malloc(sizeof(int*)*n);
	for ( int i = 0 ; i < n ; i++ ) 
		*(ret+i) = get_1d_new_array(m);
	return ret;
}
int is_possible(int R,int C,int *height,int cur_c,int cur_h,int cur_w) {
	if ( *(height+cur_c)+cur_h > R ) return false;
	if ( cur_c + cur_w > C ) return false;
	for ( int i = cur_c ; i < cur_c + cur_w - 1 ; i++ ) 
		if ( *(height+i) != *(height+(i+1)) ) 
			return false;
	return true;
}
int is_complete(int R,int C,int *height) {
	for ( int i = 0 ; i < C ; i++ ) 
		if ( *(height+i) != R ) return false;
	return true;
}
void place(int R,int C,int *height,int cur_c,int cur_h,int cur_w,int figure_id,int **state) {
	for ( int i = cur_c ; i < cur_c+cur_w ; i++ ) {
		if ( cur_h < 0 ) {
			for ( int j = *(height+i)-1 ; j >= 0 && j >= *(height+i)+cur_h ; j-- ) 
				*(*(state+j)+i) = 0;
		} else if ( cur_h > 0 ) {
			for ( int j = *(height+i) ; j < R && j < *(height+i)+cur_h ; j++ ) 
				*(*(state+j)+i) = figure_id;
		}
		*(height+i) += cur_h;
	}
}
void print_state(int R,int C,int **state) {
	for ( int i = 0 ; i < R ; i++ ) {
		for ( int j = 0 ; j < C ; j++ ) 
			printf("%d",*(*(state+i)+j));
		puts("");
	}
}
int get_taken_count(int N,int *is_taken) {
	int ret = 0;
	for ( int i = 0 ; i < N ; i++ ) 
		if ( *(is_taken+i) ) ret++;
	return ret;
}
void copy_2d_array(int R,int C,int **dest,int **state) {
	for ( int i = 0 ; i < R ; i++ ) 
		for ( int j = 0 ; j < C ; j++ ) 
			*(*(dest+i)+j) = *(*(state+i)+j);
}
void go(int R,int C,int N,int **figure,int *height,int *is_taken,int depth,int **state,int **ans_state,int *ans_cnt,int *ok,int **full_ans_state) {
	int taken_count = get_taken_count(N,is_taken);
	if ( taken_count > (*ans_cnt) ) {
		(*ans_cnt) = taken_count;
		copy_2d_array(R,C,ans_state,state);
	}
	if ( is_complete(R,C,height) ) {
		*ok = true;
		copy_2d_array(R,C,full_ans_state,state);
	}
	if ( depth >= N ) return ;
	int min_h = 222;
	for ( int i = 0 ; i < C ; i++ ) 
		min_h = min(min_h,*(height+i));
	for ( int j = 0 ; j < C ; j++ ) 
		if ( min_h == *(height+j) ) {
			for ( int i = 0 ; i < N ; i++ ) 
				if ( !(*(is_taken+i)) ) {
					if ( is_possible(R,C,height,j,*(*(figure+i)+0),*(*(figure+i)+1)) ) {
						place(R,C,height,j,*(*(figure+i)+0),*(*(figure+i)+1),i+1,state);
						*(is_taken+i) = true;
						go(R,C,N,figure,height,is_taken,depth+1,state,ans_state,ans_cnt,ok,full_ans_state);
						*(is_taken+i) = false;
						place(R,C,height,j,-(*(*(figure+i)+0)),*(*(figure+i)+1),i+1,state);
					}
					if ( is_possible(R,C,height,j,*(*(figure+i)+1),*(*(figure+i)+0)) ) {
						place(R,C,height,j,*(*(figure+i)+1),*(*(figure+i)+0),i+1,state);
						*(is_taken+i) = true;
						go(R,C,N,figure,height,is_taken,depth+1,state,ans_state,ans_cnt,ok,full_ans_state); 
						*(is_taken+i) = false;
						place(R,C,height,j,-(*(*(figure+i)+1)),*(*(figure+i)+0),i+1,state);
					}
				}
			break;
		}
}
void solve(int R,int C,int N,int **figure) {
	int * height = get_1d_new_array(C);
	int * is_taken = get_1d_new_array(N);
	int **state = get_2d_new_array(R,C);
	int **ans_state = get_2d_new_array(R,C);
	int **full_ans_state = get_2d_new_array(R,C);
	int ans_cnt = 0;
	int ok = false;

	go(R,C,N,figure,height,is_taken,0,state,ans_state,&ans_cnt,&ok,full_ans_state);
	printf("%d\n",ans_cnt);
	print_state(R,C,ans_state);
	printf("%s\n",ok?"YES":"NO");
	if ( ok ) 
		print_state(R,C,full_ans_state);

	for ( int i = 0 ; i < R ; i++ ) 
		free(*(full_ans_state+i));
	free(full_ans_state);
	for ( int i = 0 ; i < R ; i++ ) 
		free(*(ans_state+i));
	free(ans_state);
	for ( int i = 0 ; i < R ; i++ ) 
		free(*(state+i));
	free(state);
	free(is_taken);
	free(height);
}
int main() {
	int R,C,N;
	scanf("%d %d %d",&R,&C,&N);
	int **figure = get_2d_new_array(N,2);
	for ( int i = 0 ; i < N ; i++ ) {
		int r,c;
		scanf("%d %d",&r,&c);
		*(*(figure+i)+0) = r;
		*(*(figure+i)+1) = c;
	}
	solve(R,C,N,figure);
	for ( int i = 0 ; i < N ; i++ ) 
		free(*(figure+i));
	free(figure);
	return 0;
}
