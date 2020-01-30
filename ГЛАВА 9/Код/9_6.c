#include <stdio.h>

void min_av_max(double *, double *, double *);

int main(void)
{
	double a, b, c;
	int status;

	printf("Enter three numbers:\n");
	while ((status = scanf("%lf %lf %lf", &a, &b, &c)) != 3)
	{
		if (status != 3)
		{
			printf("Please enter three numbers:\n");
			scanf("%*s");
			continue;
		}
	}
	printf("a = %.2f, b = %.2f, c = %.2f.\n", a, b, c);
	min_av_max(&a, &b, &c);
	printf("a = %.2f, b = %.2f, c = %.2f.\n", a, b, c);

	return 0;
}

void min_av_max(double * a, double * b, double * c)
{
	double min, average, max;

	if (*a < *b && *a < *c)
		min = *a;
	else if (*b < *a && *b < *c)
		min = *b;
	else 
		min = *c;

	if (*a > *b && *a > *c)
		max = *a;
	else if (*b > *a && *b > *c)
		max = *b;
	else 
		max = *c;

	if (*a > min && *a < max)
		average = *a;
	else if (*b > min && *b < max)
		average = *b;
	else 
		average = *c;

	*a = min;
	*b = average;
	*c = max;

	return;
}