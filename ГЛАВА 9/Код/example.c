#include <stdio.h>

double * which(double *, double *);

int main(void)
{
	double *p;
	double a = 5.3;
	double b = 10.7;

	p = which(&a, &b);

	printf("%p.\n", &p);

	return 0;
}

double * which(double * x, double * y)
{
	double z;
	z = *x + *y;

	return &z;
}