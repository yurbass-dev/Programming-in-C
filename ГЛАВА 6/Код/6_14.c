#include <stdio.h>
#define SIZE 8
int main(void)
{
	double first[SIZE];
	double second[SIZE];

	int i, sum;
	sum = 0;

	printf("Введите %d чисел для первого массива:\n", SIZE);

	for (i = 0; i < SIZE; i++)
	{
		scanf("%lf", &first[i]);
		sum += first[i];
		second[i] = sum;
	}

	for (i = 0; i < SIZE; i++)
		printf("%5g ", first[i]);

	printf("\n");

	for (i = 0; i < SIZE; i++)
		printf("%5g ", second[i]);

	printf("\n");

	return 0;
}