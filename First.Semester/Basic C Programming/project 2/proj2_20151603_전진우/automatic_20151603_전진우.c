/*
 *	Sudoku Solver Program
 *
 *	Project 2
 *	Basic C Programming
 *
 *	20151603 전진우
 */
#include<stdio.h>
int RuleChecker(int row,int column,int sudoku[9][9]){
	int number,i,j;
	int flag;
	// column range check.
	if(column>8) return 1;
	// row range check.
	if(row>8) return RuleChecker(0,column+1,sudoku);
	// check whether sudoku square is filled.
	if(sudoku[row][column]) return RuleChecker(row+1,column,sudoku);
	// number check 1 to 9
	for(number=1;number<10;++number){
		// row,column,square value check
		// if some other sudoku square has number, escape, and then continue to next number.
		flag = 0;
		for(i=0;i<9;++i){
			if(sudoku[row][i] == number){
				flag = 1;
				break;
			}
			if(sudoku[i][column] == number){
				flag = 1;
				break;
			}
		}
		if(flag) continue;
		for(i=3*(row/3);i<3*(row/3+1);++i)
			for(j=3*(column/3);j<3*(column/3+1);++j)
				if(sudoku[i][j] == number)
					flag = 1;
		if(flag) continue;
		sudoku[row][column] = number;	
		// if next square is not filled, then empty square and continue to next square.
		if(RuleChecker(row+1,column,sudoku)==0)
			sudoku[row][column] = 0;
	}
	// if sudoku square is filled return True.
	if(sudoku[row][column]) return 1;
	// if not filled return False.
	else return 0;
}
int main(void){
	// Declaration Part
	int sudoku_table[9][9]={0,};
	int row,column;
	// Input Part
	for(column=0;column<9;++column){
		printf("Input %d row integers : ",column+1);
		for(row=0;row<9;++row)
			scanf("%d",&sudoku_table[row][column]);
	}
	// Executing Part
	for(column=0;column<9;++column)
		for(row=0;row<9;++row){
			if(sudoku_table[row][column]) continue;
			// Function Calling Part
			RuleChecker(row,column,sudoku_table);
		}
	// Output Part
	printf("┌──┬──┬──┬──┬──┬──┬──┬──┬──┐\n");
	for(column=0;column<9;++column){
		for(row=0;row<9;++row){
			printf("│ %d",sudoku_table[row][column]);
		}
		printf("│\n");
		if(column<8)
			printf("├──┼──┼──┼──┼──┼──┼──┼──┼──┤\n");
	}
	printf("└──┴──┴──┴──┴──┴──┴──┴──┴──┘\n");
	printf("Win!!\n");
	return 0;
}
