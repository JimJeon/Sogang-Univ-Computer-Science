#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef float VectorSize;
typedef float Distance;
typedef float Scalar;
typedef float* Vector_Comp;
typedef float Comp;
typedef struct vector
{
	Vector_Comp comps;
	int vec_size;
} Vector;

VectorSize vSize(Vector v);
Distance DistVector(Vector v1,Vector v2);
Scalar innerProduct(Vector v1,Vector v2);

int main(void)
{
	Vector v1;
	Vector v2;
	int i;

	printf("size of vector v1: ");
	scanf("%d",&v1.vec_size);

	v1.comps = (Vector_Comp)malloc(v1.vec_size * sizeof(Comp));

	printf("vector 1 : ");
	for(i = 0;i < v1.vec_size; ++i)
		scanf("%f",&v1.comps[i]);

	printf("size of vector v2: ");
	scanf("%d",&v2.vec_size);

	v2.comps = (Vector_Comp)malloc(v2.vec_size * sizeof(Comp));

	printf("vector 2 : ");
	for(i = 0;i < v2.vec_size; ++i)
		scanf("%f",&v2.comps[i]);

	printf("----------------------\n");
	printf("Size of v1 = %.2f\nSize of v2 = %.2f\n",vSize(v1),vSize(v2));

	if(v1.vec_size != v2.vec_size)
		return 0;
	
	printf("Distance v1.v2 = %.3f\n",DistVector(v1,v2));
	printf("Inner Product v1 * v2 = %f\n",innerProduct(v1,v2));

	return 0;
}

VectorSize vSize(Vector v)
{
	int i;
	float total = 0;
	for(i = 0;i < v.vec_size; ++i)
		total += v.comps[i]*v.comps[i];

	return sqrt(total);
}
Distance DistVector(Vector v1,Vector v2)
{
	int i;
	float total = 0;
	for(i = 0;i < v1.vec_size; ++i)
		total += pow(v1.comps[i] - v2.comps[i],2);

	return sqrt(total);
}
Scalar innerProduct(Vector v1,Vector v2)
{
	int i;
	float total = 0;
	for(i = 0;i < v1.vec_size; ++i)
		total += v1.comps[i] * v2.comps[i];

	return total;
}
