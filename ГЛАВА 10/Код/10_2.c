#include <stdio.h>
#define SIZE 5

void copy_arr(double arr_target_1[], double source[], int n);
void copy_ptr(double * pt_target_2, double * pt_source, int n);
void copy_ptrs(double arr_target_3[], double source[], double * pt_source);


int main(void)
{
	double source[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target_1[SIZE];
	double target_2[SIZE];
	double target_3[SIZE];

	// Выводим значения массивов

	printf("Исходный массив: ");
	for (int i = 0; i < SIZE; i++)
	{	
		printf("%.1f ", source[i]);
	}
	putchar('\n');

	copy_arr(target_1, source, SIZE);
	printf("Массив target_1: ");
	for (int i = 0; i < SIZE; i++)
	{	
		printf("%.1f ", target_1[i]);
	}
	putchar('\n');	

	copy_ptr(target_2, source, SIZE);
	printf("Массив target_2: ");
	for (int i = 0; i < SIZE; i++)
	{	
		printf("%.1f ", target_2[i]);
	}
	putchar('\n');	

	copy_ptrs(target_3, source, source + SIZE);
	printf("Массив target_3: ");
	for (int i = 0; i < SIZE; i++)
	{	
		printf("%.1f ", target_3[i]);
	}
	putchar('\n');	

	return 0;
}

void copy_arr(double arr_target_1[], double source[], int n)
{
	for (int i = 0; i < n; i++)
		arr_target_1[i] = source[i];
}

void copy_ptr(double * pt_target_2, double * pt_source, int n)
{
	for (int i = 0; i < n; i++, pt_target_2++, pt_source++)
		*pt_target_2 = *pt_source;
}

void copy_ptrs(double arr_target_3[], double source[], double * pt_source)
{
	while (source < pt_source) 
	{
		*arr_target_3 = *source;
		source++; 
		arr_target_3++;
	}
}


