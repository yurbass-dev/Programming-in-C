#include <stdio.h>

void large_of(double *, double *);

int main(void)
{
	double x, y;
	int status;

	printf("Enter two numbers:\n");
	while ((status = scanf("%lf %lf", &x, &y)) != 2)
	{
		if (status != 2)
		{
			printf("Please enter two numbers:\n");
			scanf("%*s");
			continue;
		}
	}
	printf("x = %f, y = %f\n", x, y);
	large_of(&x, &y);
	printf("x = %f, y = %f\n", x, y);

	return 0;
}

void large_of(double * x, double * y)
{
	*x > *y ? *y = *x : *x = *y;

	/* Alternative method
	if (*x > *y)
		*y = *x;
	else
		*x = *y;
	*/
}

