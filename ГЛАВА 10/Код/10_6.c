#include <stdio.h>
#define SIZE_OF_ARRAY 10

void show_array(double * arr, int n);
void change_following_array(double * arr, int n);

int main(void)
{
	double array[SIZE_OF_ARRAY] = {1.3, 2.4, 3.2, 4.8, 5.1, 6.7, 7.9, 8.4, 9.3, 10.5};

	show_array(array, SIZE_OF_ARRAY);
	printf("Меняем порядок следования на противоположный:\n");
	change_following_array(array, SIZE_OF_ARRAY);

	return 0;
}

void show_array(double * arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("%.1f ", *(arr + i));
		putchar('\n');
}

void change_following_array(double * arr, int n)
{
	for (int i = n - 1; i > -1; i--)
		printf("%.1f ", *(arr + i));
		putchar('\n');
}