#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int compare(const void * p1, const void * p2);
void clear(void);
int binary_search(int arr[], int size, int num);

int main(void)
{
	int arr[SIZE];
	int num;
	int i = 0, j = 0;

	printf("Введите числа для массива (q для выхода):\n");
	while (scanf("%d", &num) == 1 && i < SIZE)
	{
		clear();
		arr[i] = num;
		i++;
	}
	clear();
	if (i == SIZE)
		printf("Вы ввели максимально возможное количество чисел.\n");
	else if (i > 0)
	{
		printf("Введите число, которое хотите найти в массиве:\n");
		for (j = 0; j < i; j++)
		{
			printf("%d ", arr[j]);
		}
		putchar('\n');
		scanf("%d", &num);
		clear();
		qsort(arr, i, sizeof(int), compare);
		printf("%d %s в массиве.\n",num, binary_search(arr, i, num) ? "есть" : "нету");

	}
	puts("Программа завершена!");

	return 0;
}

int compare(const void * p1, const void * p2)
{
	if (*(int*)p1 > *(int*)p2)
		return 1;
	else if (*(int*)p1 < *(int*)p2)
		return -1;
	else
		return 0;
}

void clear(void)
{
	while (getchar() != '\n')
		continue;
}

int binary_search(int arr[], int size, int num)
{
	int temp_num;
	int mid;
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		mid = (left + right) / 2;
		temp_num = arr[mid];

		if (num == temp_num)
			return 1;
		else
		{
			if (num < temp_num)
			{
				right = mid - 1;
				continue;
			}
			else
			{
				left = mid + 1;
				continue;
			}
		}
	}

	return 0;
}