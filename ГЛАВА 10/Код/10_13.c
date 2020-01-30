#include <stdio.h>
#define ROWS 3
#define COLS 5

void save_arr(double arr[][COLS], int rows);
double average_for_each_set(double arr[], int n);
double average_of_all(double arr[][COLS], int rows);
double max_of_all(double arr[][COLS], int rows);

int main(void)
{
	double array[ROWS][COLS];
	double aver_for_each_set;
	double aver_of_all;
	double max;

	save_arr(array, ROWS);

	for (int row = 0; row < ROWS; row++)
	{
		printf("Среднее значение для %d-го набора: ", row + 1);
		aver_for_each_set = average_for_each_set(array[row], COLS);
		printf("%g\n", aver_for_each_set);
	}

	aver_of_all = average_of_all(array, ROWS);
	printf("Cреднее значение из всех значений: %g\n", aver_of_all);

	max = max_of_all(array, ROWS);
	printf("Наибольшее значение из всех: %g\n", max);

	return 0;
}

void save_arr(double arr[][COLS], int rows)
{
	printf("Введите три набора по пять чисел:\n");
	for (int row = 0; row < ROWS; row++)
	{
		printf("%d-й: ", row + 1);
		for (int col = 0; col < COLS; col++)
		{
			scanf("%lf", &arr[row][col]);
		}
	}
}

double average_for_each_set(double arr[], int n)
{
	double average = 0.0;

	for (int i = 0; i < n; i++)
		average += arr[i];
	average /= n;

	return average;
}

double average_of_all(double arr[][COLS], int rows)
{
	double average = 0.0;
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			average += arr[row][col];
		}
	}
	average /= (rows * COLS);

	return average;
}

double max_of_all(double arr[][COLS], int rows)
{
	double max = arr[0][0];

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			if (max < arr[row][col])
				max = arr[row][col];
		}
	}

	return max;
}
