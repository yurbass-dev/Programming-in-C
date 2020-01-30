#include <stdio.h>
#define SIZE_OF_ARRAY 10

double diff_max_of_min(double arr[], int n, int *pt_min, int *pt_max);

int main(void)
{
	double array[SIZE_OF_ARRAY] = {1.3, 2.4, 3.2, 4.8, 5.1, 6.7, 7.9, 8.4, 9.3, 10.5};
	double diff;
	int min;
	int max;
	
	diff = diff_max_of_min(array, SIZE_OF_ARRAY, &min, &max);

	printf("Разность между наибольшим и наименьшим значением массива составляет:\n%.1f - %.1f = %.1f.\n", 
		    array[max], array[min], diff);

	return 0;
}


double diff_max_of_min(double arr[], int n, int *pt_min, int *pt_max)
{
	double difference;
	double min = arr[0];
	double max = arr[0];

	*pt_min = 0;
	*pt_max = 0;

	for (int i = 1; i < n; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
			*pt_min = i;
		}
		else if (max < arr[i])
		{
			max = arr[i];
			*pt_max = i;
		}
	}

	difference = max - min;

	return difference;
}