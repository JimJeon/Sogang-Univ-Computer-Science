#include<stdio.h>
#include<stdlib.h>

int insert(int row,int col,int y,int x,int **room,int **box,int number,int rotate);
/* Name : insert
 * Return : If insertion succeeded return 1, if failed return 0,
 *			if box exceeds the limit of room return -1.
 * Function : Check whether room is empty, if it is empty do insertion.
 */
void initialize(int y,int x,int **room,int height,int width);
/* Name : initialize
 * Return : void
 * Function : Initialize room from (x,y) to (x+width-1,y+height-1) with 0.
 */
void PROBLEM_SOLVE(int row,int col,int **room,int **box,int number,int *MAX,int ***FINAL_ROOM,int ***FULL_ROOM,int *box_in,int *breakpoint,int* full);
/* Name : PROBLEM_SOLVE
 * Return : void
 * Function : 
 */
void print_room(int **room,int row,int col);
/* Name : print_room
 * Return : void
 * Function : Prints double pointer with box shape.
 */
int** roomcpy(int **room,int row,int col);
/* Name : roomcpy
 * Return : Return copied double pointer.
 * Function : Make new double pointer and copy room to it.
 */
int** free2dim(int **target,int row);
/* Name : free2dim
 * Return : NULL
 * Function : Free double pointer.
 */
int fullCheck(int **room,int row,int col);
/* Name : fullCheck
 * Return : If there exists any box of room that is 0, then return 0. If not return 1.
 * Function : Check the room is full or not.
 */
void boxSort(int ***box,int number);
/* Name : boxSort
 * Return : void
 * Function : Sort box array in ascending order with bubble sort.
 */
int main(void)
{
	// Declaration, Input and Memory allocation
	int **room = NULL;
	int row = 0;
	int col = 0;

	int **box = NULL;
	int number = 0;

	int i,j,r;
	int box_in = 0;
	int breakpoint = 0;
	int full = 0;

	int MAX = 0;
	int **FINAL_ROOM = NULL;
	int **FULL_ROOM = NULL;

	scanf("%d%d%d",&row,&col,&number);
	room = (int**)malloc(row * sizeof(int*));
	for(i = 0;i < row; ++i)
		*(room + i) = (int*)calloc(col,sizeof(int));

	box = (int**)malloc(number * sizeof(int*));
	for(i = 0;i < number; ++i)
	{
		*(box + i) = (int*)calloc(3,sizeof(int));
		scanf("%d%d",*(box + i),*(box + i) + 1);
		*(*(box + i) + 2) = i + 1;
	}

	// Box Sorting
	boxSort(&box,number);

	// Problem Solving
	PROBLEM_SOLVE(row,col,room,box,number-1,&MAX,&FINAL_ROOM,&FULL_ROOM,&box_in,&breakpoint,&full);

	// Output
	printf("%d\n",MAX);
	print_room(FINAL_ROOM,row,col);
	if(full)
	{
		printf("YES\n");
		print_room(FULL_ROOM,row,col);
		free2dim(FULL_ROOM,row);
	}
	else printf("NO\n");

	// Free all used memory
	free2dim(room,row);
	free2dim(box,number);
	free2dim(FINAL_ROOM,row);
	
	return 0;
}
int insert(int row,int col,int y,int x,int **room,int **box,int number,int rotate)
{
	int i,j;
	int init_i,init_j;
	// Check if box exceeds the limit of room. If it does return -1.
	if(y + *(*(box + number) + rotate) > row) return -1;
	if(x + *(*(box + number) + (rotate + 1) % 2) > col) return -1;
	// Check if there exists space in room to put in a box. If not return 0.
	for(i = 0;i < *(*(box + number) + rotate); ++i)
		for(j = 0;j < *(*(box + number) + (rotate + 1) % 2); ++j)
			if(*(*(room + y + i) + x + j) != 0)
				return 0;
	// Insert box, and return 1.
	for(i = 0;i < *(*(box + number) + rotate); ++i)
		for(j = 0;j < *(*(box + number) + (rotate+1) % 2); ++j)
			*(*(room + y + i) + x + j) = *(*(box + number) + 2);
	return 1;
}
void initialize(int y,int x,int **room,int height,int width)
{
	int i,j;
	// Initialize room with 0 from (x,y) to (x+width-1,y+height-1).
	for(i = 0;i < height; ++i)
		for(j = 0;j < width; ++j)
			*(*(room + y + i) + x + j) = 0;
	return;
}
void PROBLEM_SOLVE(int row,int col,int **room,int **box,int number,int *MAX,int ***FINAL_ROOM,int ***FULL_ROOM,int *box_in,int *breakpoint,int* full)
{
	int i,j,rotate;
	int box_jump = 0;
	// rotate means (is it rotated?) True or False.
	for(rotate = 0;rotate < 2; ++rotate)
		for(i = 0;i <= row - *(*(box + number) + rotate); ++i)
			for(j = 0;j <= col - *(*(box + number) + (rotate+1)%2); ++j)
			{	
				// box_jump is used for save the result of insert().
				box_jump = insert(row,col,i,j,room,box,number,rotate);
				// If box_jump is -1, then break.
				// Comparing with 0 is much faster than the others, so I wrote like that.
				if(box_jump + 1 == 0) break;
				if(box_jump)
				{
					*box_in += 1;
					if(number == 0)
					{
						if(fullCheck(room,row,col))
						{
							if(*FULL_ROOM != NULL)
								*FULL_ROOM = free2dim(*FULL_ROOM,row);

							*full = 1;
							*FULL_ROOM = roomcpy(room,row,col);
						}

						if(*MAX < *box_in)
						{
							if(*FINAL_ROOM != NULL)
								*FINAL_ROOM = free2dim(*FINAL_ROOM,row);

							*MAX = *box_in;
							*FINAL_ROOM = roomcpy(room,row,col);
						}
						initialize(i,j,room,*(*box + rotate),*(*box + (rotate + 1) % 2));
						*box_in -= 1;
						if(*breakpoint == number)
						{
							*breakpoint += 1;
							return;
						}
					}
					
					PROBLEM_SOLVE(row,col,room,box,number-1,MAX,FINAL_ROOM,FULL_ROOM,box_in,breakpoint,full);
					initialize(i,j,room,*(*(box + number) + rotate),*(*(box + number) + (rotate + 1) % 2));
					*box_in -= 1;

					if(*breakpoint == number)
					{
						*breakpoint += 1;
						return;
					}
				}
				*breakpoint = 0;
			}
	if(number == 0)
	{
		if(fullCheck(room,row,col))
		{
			if(*FULL_ROOM != NULL)
				*FULL_ROOM = free2dim(*FULL_ROOM,row);

			*full = 1;
			*FULL_ROOM = roomcpy(room,row,col);
		}
		if(*MAX < *box_in)
		{
			if(*FINAL_ROOM != NULL)
				*FINAL_ROOM = free2dim(*FINAL_ROOM,row);

			*MAX = *box_in;
			*FINAL_ROOM = roomcpy(room,row,col);
		}
		return;
	}
	PROBLEM_SOLVE(row,col,room,box,number-1,MAX,FINAL_ROOM,FULL_ROOM,box_in,breakpoint,full);
	return;
}
void print_room(int **room,int row,int col)
{
	int i,j;
	for(i = 0;i < row; ++i)
	{
		for(j = 0;j < col; ++j)
			printf("%d",*(*(room + i) + j));
		puts(""); // new line
	}
}
int** roomcpy(int **room,int row,int col)
{
	int **target = (int**)malloc(row*sizeof(int*)); // new double pointer which size is same with room.
	int i,j;
	for(i = 0;i < row; ++i)
		*(target + i) = (int*)malloc(col*sizeof(int));
	// Copy all status of the room to new double pointer, target.
	for(i = 0;i < row; ++i)
		for(j = 0;j < col; ++j)
			*(*(target + i) + j) = *(*(room + i) + j);
	return target;
}
int** free2dim(int **target,int row)
{
	int i;
	// Free single pointer first.
	for(i = 0;i < row; ++i)
		free(*(target + i));
	free(target);
	return NULL;
}
int fullCheck(int **room,int row,int col)
{
	int i,j;
	for(i = 0;i < row; ++i)
		for(j = 0;j < col; ++j)
			if(!*(*(room + i) + j))
				return 0;
	// If there exists any box of room that is 0, then return 0
	return 1;
}
void boxSort(int ***box,int number)
{
	int i,temp;
	while(--number)
		for(i = 1;i <= number; ++i)
			if(**(*box + i)* *(*(*box + i) + 1) < **(*box + i - 1) * *(*(*box + i - 1) + 1))
			{
				// Change first index of box
				temp = **(*box + i);
				**(*box + i) = **(*box + i - 1);
				**(*box + i - 1) = temp;
				// Change second index of box
				temp = *(*(*box + i) + 1);
				*(*(*box + i) + 1) = *(*(*box + i - 1) + 1);
				*(*(*box + i - 1) + 1) = temp;
				// Change third index of box
				temp = *(*(*box + i) + 2);
				*(*(*box + i) + 2) = *(*(*box + i - 1) + 2);
				*(*(*box + i - 1) + 2) = temp;
			}
}
