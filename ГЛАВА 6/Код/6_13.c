#include <stdio.h>
#include <math.h>
#define SIZE 8
int main(void)
{
	int num[SIZE];
	int i;

	for (i = 0; i < SIZE; i++)
		num[i] = pow(2, i);


	printf("Два в степени   Равно\n");

	i = 0;

	do
	{
		printf("%7d %12d", i, num[i]);
		printf("\n");
	}
	while (i++ < SIZE - 1);

	return 0;
}