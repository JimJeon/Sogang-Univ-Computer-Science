#include<stdio.h>
#include<stdlib.h>
#include<string.h>

union utemp
{
	int i;
	float f;
	double d;
};

typedef struct
{
	int type;
	char name[20];
	union utemp u;
} stemp;

void power(stemp *s);

int main(void)
{
	int testcase;
	stemp* number;
	int i;

	printf("Number of Iterations : ");
	scanf("%d",&testcase);

	number = malloc(testcase*sizeof(stemp));

	for(i = 0;i < testcase; ++i)
	{
		printf("Type [1 for int, 2 for float, 3 for double] : ");
		scanf("%d",&number[i].type);
		
		switch(number[i].type)
		{
			case 3:
				printf("Enter a double value : ");
				scanf("%lf",&number[i].u.d);
				strcpy(number[i].name,"double");
				break;
			case 2:
				printf("Enter a float value : ");
				scanf("%f",&number[i].u.f);
				strcpy(number[i].name,"float");
				break;
			case 1:
				printf("Enter a integer value : ");
				scanf("%d",&number[i].u.i);
				strcpy(number[i].name,"integer");
				break;
		}
		
		power(&number[i]);

	}
	puts("----------Result----------");
	for(i = 0;i < testcase; ++i)
		switch(number[i].type)
		{
			case 1:
				printf("%-10s: %d\n",number[i].name,number[i].u.i);
				break;
			case 2:
				printf("%-10s: %.4f\n",number[i].name,number[i].u.f);
				break;
			case 3:
				printf("%-10s: %.4lf\n",number[i].name,number[i].u.d);
				break;
		}
	return 0;
}

void power(stemp *s)
{
	switch(s->type)
	{
		case 1:
			s->u.i = s->u.i*s->u.i;
			break;
		case 2:
			s->u.f = s->u.f*s->u.f;
			break;
		case 3:
			s->u.d = s->u.d*s->u.d;
			break;
	}

}
