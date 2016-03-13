#include<stdio.h>

typedef struct _sphere
{
	double x;
	double y;
	double z;
	double r;
} SPHERE;

double Distance( SPHERE O1,SPHERE O2 );
double CrossSectionArea( SPHERE O1,SPHERE O2 );
double SurfaceArea( SPHERE O1,SPHERE O2 );
double Volume( SPHERE O1,SPHERE O2 );

int main(void)
{
	SPHERE O1, O2;
	double d;
	
	printf("Type First Sphere Coordinate : ");
	scanf("%lf%lf%lf",&O1.x,&O1.y,&O1.z);
	printf("Type First Sphere Radius : ");
	scanf("%lf",&O1.r);
	printf("Type Second Sphere Coordinate : ");
	scanf("%lf%lf%lf",&O2.x,&O2.y,&O2.z);
	printf("Type Second Sphere Radius : ");
	scanf("%lf",&O2.r);

	d = Distance(O1,O2);

	if( d > (O1.r + O2.r)*(O1.r + O2.r))
		printf("Sum of Cross Section Area : %.2lf\n",CrossSectionArea(O1,O2));
	else if( d == (O1.r + O2.r)*(O1.r + O2.r))
		printf("Sum of Surface Area : %.2lf\n",SurfaceArea(O1,O2));
	else if( d < (O1.r + O2.r)*(O1.r + O2.r))
		printf("Sum of Volume : %.2lf\n",Volume(O1,O2));

	return 0;
}
double Distance( SPHERE O1,SPHERE O2 )
{
	return  (O1.x - O2.x)*(O1.x - O2.x) + (O1.y - O2.y)*(O1.y - O2.y) + (O1.z - O2.z)*(O1.z - O2.z);
}
double CrossSectionArea( SPHERE O1,SPHERE O2 )
{
	return O1.r*O1.r*3.14 + O2.r*O2.r*3.14;
}
double SurfaceArea( SPHERE O1,SPHERE O2 )
{
	return 4 * CrossSectionArea(O1,O2);
}
double Volume( SPHERE O1,SPHERE O2 )
{
	return (4/3) * (3.14 * O1.r * O1.r * O1.r + 3.14 * O2.r * O2.r * O2.r);
}
