#include<stdio.h>

typedef struct fraction
{
	int numerator;
	int denominator;
} FRACTION;

void multFr(FRACTION* pFr1, FRACTION* pFr2, FRACTION* pRes);

int main(void)
{
	FRACTION fr1, fr2, Res;
	char tmp;

	printf("x/y : ");
	scanf("%d%c%d",&fr1.numerator,&tmp,&fr1.denominator);
	printf("x/y : ");
	scanf("%d%c%d",&fr2.numerator,&tmp,&fr2.denominator);

	multFr(&fr1,&fr2,&Res);
	printf("%d/%d * %d/%d = %d/%d\n",fr1.numerator,fr1.denominator,fr2.numerator,fr2.denominator,Res.numerator,Res.denominator);

	return 0;
}

void multFr(FRACTION* pFr1, FRACTION* pFr2, FRACTION* pRes)
{
	pRes->numerator = pFr1->numerator * pFr2->numerator;
	pRes->denominator = pFr1->denominator * pFr2->denominator;

	return;
}
