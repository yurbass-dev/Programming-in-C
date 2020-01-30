#include <stdio.h>
#define ROWS 3
#define COLS 5

void show_arr(int rows, int cols, double arr[rows][cols]);
void copy_arr(int rows, int cols, double arr[rows][cols], double original[][COLS]);

int main(void)
{
	double original[ROWS][COLS] = 
	{
		{1.1, 1.2, 1.3, 1.4, 1.5},
		{2.1, 2.2, 2.3, 2.4, 2.5},
		{3.1, 3.2, 3.3, 3.4, 3.5}
	};
	int rows = 3;
	int cols = 5;
	double copy[rows][cols];

	show_arr(rows, cols, original);
	copy_arr(rows, cols, copy, original);
	show_arr(rows, cols, copy);

	return 0;
}

void show_arr(int rows, int cols, double arr[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%.1f ", arr[i][j]);
		putchar('\n');
	}
	putchar('\n');
}

void copy_arr(int rows, int cols, double arr[rows][cols], double original[][COLS])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			arr[i][j] = original[i][j];
	}
}
