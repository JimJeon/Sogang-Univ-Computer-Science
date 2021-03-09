#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define BNUM 256	//	the maximum length of a line
#define LIMIT 36	//	# of chars to print out in a line

void Remove_Blanks_At_The_End( char *line );
void Print_Line( char *line, int *Count, int *B_Flag );
void Get_Blanks_Chars( char *line, int Start, int *N_Blanks, int *N_Chars );
