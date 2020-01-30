#include <stdio.h>

int max_of_arr(int ar[], int n);

int main(void)
{
	int arr[10] = {70, 60, 3, 6, 150, -46, 28, 31, 0, 77};

	printf("Максимальное значение в массиве: %d.\n", max_of_arr(arr, 10));

	return 0;
}

int max_of_arr(int ar[], int n)
{
	int max = ar[0];

	for (int i = 1; i < n; i++)
	{
		if (max < ar[i])
			max = ar[i];
	}
	return max;
}