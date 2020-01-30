#include <stdio.h>
#define SIZE 5

void summ_ar(int first_arr[], int second_arr[], int summ_arr[], int size);
void show_ar(int arr[], int size);

int main(void)
{
	int first_arr[SIZE] = {4, 6, 20, 13, 7};
	int second_arr[SIZE] = {6, 12, 5, 17, 23};
	int summ_arr[SIZE];

	printf("Первый массив:\n");
	show_ar(first_arr, SIZE);
	printf("Второй массив:\n");
	show_ar(second_arr, SIZE);
	summ_ar(first_arr, second_arr, summ_arr, SIZE);
	printf("Сумма первого и второго массивов:\n");
	show_ar(summ_arr, SIZE);

	return 0;
}

void show_ar(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	putchar('\n');
}

void summ_ar(int first_arr[], int second_arr[], int summ_arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		summ_arr[i] = first_arr[i] + second_arr[i];
	}
}