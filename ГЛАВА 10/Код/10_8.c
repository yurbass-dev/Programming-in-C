#include <stdio.h>

void copy_arr(double copy_array[], double source[], int n);
void show_copy_arr(double copy_array[], int n);

int main(void)
{
	double source[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	double copy_array[3];

	copy_arr(copy_array, source + 2, 3);
	show_copy_arr(copy_array, 3);

	return 0;
}

void copy_arr(double copy_array[], double source[], int n)
{
	for (int i = 0; i < n; i++)
		copy_array[i] = source[i];
}

void show_copy_arr(double copy_array[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%.1f ", copy_array[i]);
	putchar('\n');
}