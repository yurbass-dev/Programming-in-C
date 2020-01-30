#include <stdio.h>
int main(void)
{
	double value;
	for (value = 36; value > 0; value /= 2)
		printf("%3f", value);

	return 0;
}