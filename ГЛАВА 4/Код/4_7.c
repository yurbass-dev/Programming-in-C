#include <stdio.h>
#include <float.h>
int main(void)
{
	float a = 1.0 / 3.0;
	double b = 1.0 / 3.0;

	printf("Float = %.4f, Double = %.4f.\n", a, b);
	printf("Float = %.12f, Double = %.12f.\n", a, b);
	printf("Float = %.16f, Double = %.16f.\n", a, b);
	printf("Точность значений типа float = %d знаков.\n", FLT_DIG);
	printf("Точность значений типа double = %d знаков.\n", DBL_DIG);

	return 0;

}