#include <stdio.h>
#define SIZE 10

int index_max_of_arr(double arr[], int n); 	 //возвращает индекс наибольшнго значения в массиве

int main(void)
{
	double array[SIZE] = {1.0, 2.0, 30.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
	int index_of_max;

	index_of_max = index_max_of_arr(array, SIZE);
	printf("Индекс наибольшего значения в массиве: %d.\n", index_of_max);

	return 0;
}

int index_max_of_arr(double arr[], int n)
{
	int index = 0;
	double max = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			index = i;
		}
	}

	return index;
}