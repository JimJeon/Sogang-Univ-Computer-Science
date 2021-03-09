#include "Header.h"

int main(int argc, char *argv[]) {
	FILE *fp;
	char *line1, *line2, *tmpline;
	int  Count, Blanks = 0;
	int  i, B_Flag, B_Line;

    // Argument number check
	if ( argc != 2 ) {
		printf("Usage: fmt filename | > outfile\n");
        exit(-1);
	}
    // File open and error check
	fp = fopen(argv[1],"r");
	if ( fp == NULL ) {
		printf("File open error.\n");
        exit(-1);
	}
    // Memory allocation for Buffers and error check
	line1 = (char *)malloc(BNUM * sizeof(char));
	line2 = (char *)malloc(BNUM * sizeof(char));
	if ( line1 == NULL || line2 == NULL ) {
		printf("Memory allocation error\n");
		exit(-1);
	}
    // from fp read BNUM of chars to line1
    // read L1
	if ( fgets(line1, BNUM, fp) == NULL ) {
		// empty file, just return
		return 0;
	}
    // remove the followig blanks
	Remove_Blanks_At_The_End(line1);
    // check whether line 1 is empty
    // if so, then print '\n'
    // output '\n'
	if ( line1[0]=='\n' ) {
		putchar('\n');
	}
    // Count variable initialize
	Count = 0;
    // infinite loop
	while ( 1 ) {
        // check whether B_Line is 0
        // if so, then print line 1
        // output L1
		if ( B_Line == 0 ) {
			Print_Line( line1, &Count, &B_Flag);
		}
		else {
			B_Line = 0;
		}
        // check whether count is not 0
        // if so, then set B_Flag
		if ( Count != 0 ) {
			B_Flag = 1;
		}
        // from fp read BNUM of chars to line2
        // read L2
		if ( fgets(line2, BNUM, fp) == NULL ) {
			break;	// EOF. Exit the while loop
		}
        // remove the following blanks
		Remove_Blanks_At_The_End(line2);
        // check whether line 2 is ' ' and count is not 0
        // if so, then print '\n' and unset B_FLAG
        // output '\n'
		if ( line2[0] == ' ' && Count != 0) {
			putchar('\n');
			B_Flag = 0;
            Count = 0; // edited
		}
        // if line 2 is '\n' and B_Flag is set,
        // then print '\n' and unset B_Flag
		else if ( line2[0] == '\n' ) {
			if ( B_Flag == 1 ) {
				putchar('\n');
                B_Flag = 0; // edited
			}
			putchar('\n');
            Count = 0; // edited
			B_Line = 1;
		}
        // SWAP lines
		tmpline = line1;
		line1 = line2;
		line2 = tmpline;
	} 
	if ( line1[0] != '\n' ) {
		// if the last line is not empty line,
		// check if the last char is '\n' and output it if it is.
		for ( i = 0; ; i++ ) {
			if ( (line1[i] == '\n') || (line1[i] == '\0') ) {
				break;
			}
		}
		if ( line1[i] == '\n' ) {
            putchar('\n');
		}
	}
}



