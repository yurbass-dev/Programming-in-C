#include <stdio.h>

double average_harmonic(double, double);

int main(void)
{
	double first, second;
	int status;

	printf("Please enter two numbers for calculate average harmonic:\n");

	while (status = (scanf("%lf %lf", &first, &second)) != 2)
	{
		if (status != 2)
		{
			printf("\nEnter two numbers:\n");
			scanf("%*s");
			continue;	
		}
	}

	printf("Average harmonic of two numbers %.2f and %.2f = %.2f.\n", first, second, average_harmonic(first, second));

	return 0;
}

double average_harmonic(double first, double second)
{
	double average_harmonic;

	average_harmonic = 2 / ((1 / first) + (1 / second));

	return average_harmonic;
}