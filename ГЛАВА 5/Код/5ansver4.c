#include <stdio.h>
int main(void)
{
	int i = 1;
	float n;
	printf("Будьте внимательны! Далее идет последовательность дробей!\n");
	while ( i++ < 30)
	{
		n = 1.0 / i;
		printf("%.3f\n", n);
	}
	printf("На этом все!\n");

	return 0;
}
