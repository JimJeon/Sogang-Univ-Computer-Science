#include "Header.h"

void Print_Line( char *line, int *Count, int *B_Flag ) {
	int i, N_Blanks = 0, N_Chars = 0, Start = 0; // edited

	Get_Blanks_Chars( line, Start, &N_Blanks, &N_Chars );
	while ( N_Chars != 0 ) {
        // +1 is for putchar(' ');
		if ( (*B_Flag == 1) && ((*Count + N_Chars + 1) <= LIMIT) ) {

			/* In this part, N_Blanks == 0 in order that L1 and L2 should be merged.
			 * "N_Blanks != 0" means that L2 is written at the next line.
			 */
			if ( N_Blanks != 0 ) {
				printf("Something Wrong!\n");
				exit(-1);
			}

			putchar(' ');
		
			for ( i = Start; i < Start + N_Chars; i++ ) { // edited
				putchar(line[i]);
			}
            // go to next word
			Start = Start + N_Chars;
            // + is for putchar(' ');
			*Count = *Count + N_Chars + 1;
            // next Get_Blanks_Chars
			Get_Blanks_Chars( line, Start, &N_Blanks, &N_Chars );

            *B_Flag = 0; // edited
		}
		else if ( (*Count + N_Blanks + N_Chars) <= LIMIT ) {
			for ( i = Start; i < Start + N_Blanks + N_Chars; i++ ) { // edited
				putchar(line[i]);
			}
			Start = Start + N_Blanks + N_Chars;
			*Count = *Count + N_Blanks + N_Chars;
			Get_Blanks_Chars( line, Start, &N_Blanks, &N_Chars );
		}
		else {
			if ( *Count == 0 ) {
				for ( i = Start; i < Start + N_Blanks + N_Chars; i++ ) { // edited
					putchar(line[i]);
				}
				Start = Start + N_Blanks + N_Chars;
				putchar('\n');
				Get_Blanks_Chars( line, Start, &N_Blanks, &N_Chars );
                Start = Start + N_Blanks;
                N_Blanks = 0;
			}
			else {
				putchar('\n');
				*B_Flag = 0;
				for ( i = Start + N_Blanks; i < Start + N_Blanks + N_Chars; i++ ) { // edited
					putchar(line[i]);
				}
				Start = Start + N_Blanks + N_Chars;
				*Count = N_Chars;
				Get_Blanks_Chars( line, Start, &N_Blanks, &N_Chars );
			}
		}
	}
}
