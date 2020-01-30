#include <stdio.h>
#define ROWS 3
#define COLS 5

void show_ar(int arr[][COLS], int rows);
void double_ar(int arr[][COLS], int rows);

int main(void)
{
	int original_array[ROWS][COLS] = 
	{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15}
	};

	show_ar(original_array, ROWS);
	double_ar(original_array, ROWS);
	show_ar(original_array, ROWS);

	return 0;
}

void show_ar(int arr[][COLS], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%d ", arr[i][j]);
		putchar('\n');
	}
	putchar('\n');
}

void double_ar(int arr[][COLS], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 5; j++)
			arr[i][j] *= 2;
	}
}

