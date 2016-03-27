// SM_ADD.cpp : Defines the entry point for the console application.
//
#define SIGN_THRESHOLD        128
#define MASK_SIGN             0x80

#include <stdio.h>

bool SM_ADD_SUB ( // Return true if normal addition or subtraction. Return false if overflow.
	unsigned char A, unsigned char B, // two 8 bit signed magnitude numbers
	int ADD_SUB_FLAG, // 0 : S = A + B, 1 : S = A ? B
	unsigned char *S // Sum
);

char Convert_SM_to_Decimal( unsigned char S );

int main(void) {
	int t, TN, iA, iB, Flag;
	unsigned char A, B, S;
	char DA, DB, DS;
	bool NOVF;	// Non overflow flag

	scanf("%d", &TN);	// get the number of test cases

	for ( t = 0; t < TN; t++ ) {
		scanf("%d %d %d", &iA, &iB, &Flag);	// use int type for scanf 
		A = iA; B = iB;		// convert 32bits to 8 bits
		NOVF = SM_ADD_SUB ( A, B, Flag, &S );
		DA = Convert_SM_to_Decimal( A );
		DB = Convert_SM_to_Decimal( B );
		DS = Convert_SM_to_Decimal( S );
		if ( t != 0 ) {
			printf("\n");
		}
		if ( Flag == 0 ) {
			printf("%4d + %4d = %4d (%4d) ",DA, DB, DS, S);
		}
		else {
			printf("%4d - %4d = %4d (%4d) ",DA, DB, DS, S);
		}
		if ( NOVF == false ) {
			printf("(overflow)");
		}
		else {
			printf("          ");
		}
		if ( S == SIGN_THRESHOLD ) {	// negative zero
			printf("*** NEGATIVE ZERO DETECTED ***");
		}
	}
}

char Convert_SM_to_Decimal( unsigned char A ) {
	char D = (char) A;

	if ( A >= SIGN_THRESHOLD ) { // negative number
		D = -(char)(A - SIGN_THRESHOLD);
	}

	return D;
}

