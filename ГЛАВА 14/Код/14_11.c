#include <stdio.h>
#include <math.h>
#define SIZE 10
#define PI 3.14159265

void transform(double source[], double target[], int size, double (*pf)(double));

int main(void)
{
	double source[SIZE] = {30.0, 100.0, 25.5, 180.0, 0.0, 99.9, 10.0, 50.5, 120.0, 360.0};
	double target[SIZE];

	transform(source, target, SIZE, sin);


	return 0;
}

void transform(double source[], double target[], int size, double (*pf)(double))
{
	int i;
	for (i = 0; i < size; i++)
	{
		target[i] = (*pf)(source[i] * PI / 180);
		printf("Синус угла %.2lf = %.2lf градусов.\n", source[i], target[i]);
	}
}