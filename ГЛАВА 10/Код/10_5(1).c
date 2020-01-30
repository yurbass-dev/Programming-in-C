#include <stdio.h>
#define SIZE_OF_ARRAY 10

double diff_max_of_min(double arr[], int n, double *pt_min, double *pt_max);

int main(void)
{
	double array[SIZE_OF_ARRAY] = {1.3, 2.4, 3.2, 0.8, 5.1, 6.7, 7.9, 18.4, 9.3, 10.5};
	double diff;
	double min;
	double max;
	
	diff = diff_max_of_min(array, SIZE_OF_ARRAY, &min, &max);


	printf("Разность между наибольшим и наименьшим значением массива составляет:\n%.1f - %.1f = %.1f.\n", 
		    max, min, diff);

	return 0;
}


double diff_max_of_min(double arr[], int n, double *pt_min, double *pt_max)
{
	double difference;
	double min = arr[0];
	double max = arr[0];

	*pt_min = arr[0];
	*pt_max = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
			*pt_min = min;
		}
		else if (max < arr[i])
		{
			max = arr[i];
			*pt_max = max;
		}
	}

	difference = max - min;

	return difference;
}