#include <stdio.h>
#define ROWS 5
#define COLS 7
void show_source(double source[][COLS], int n);
void copy_arr(double copy_array[][COLS], double source[][COLS], int n);
void show_copy(double copy_array[][COLS], int n);


int main(void)
{
	double source[ROWS][COLS] = 
	{
		{1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7},
		{2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7},
		{3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7},
		{4.1, 4.2, 4.3, 4.4, 4.5, 4.6, 4.7},
		{5.1, 5.2, 5.3, 5.4, 5.5, 5.6, 5.7}
	};
	double copy_array[ROWS][COLS];

	show_source(source, ROWS);
	copy_arr(copy_array, source, ROWS);
	show_copy(copy_array, ROWS);

	return 0;
}

void show_source(double source[][COLS], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < COLS; j++)
			printf("%.1f ", source[i][j]);
		putchar('\n');
	}
	putchar('\n');
}

void copy_arr(double copy_array[][COLS], double source[][COLS], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < COLS; j++)
			copy_array[i][j] = source[i][j];
	}
}

void show_copy(double copy_array[][COLS], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < COLS; j++)
			printf("%.1f ", copy_array[i][j]);
		putchar('\n');
	}
}

