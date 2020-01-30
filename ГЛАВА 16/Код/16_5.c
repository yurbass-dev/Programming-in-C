#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define NUM_SEL 10


void random_select(int ar[], int size, int number_select);

int main(void)
{
	int num_array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	random_select(num_array, SIZE, NUM_SEL);

	puts("Программа завершена!");

	return 0;
}

void random_select(int ar[], int size, int number_select)
{
	int index_ar;							// случайный индекс массива
	int temp_ar[number_select];				// массив для хранения уже выведенных значений (чтобы не было повторов)
	int i, j;
	bool check = false;

	srand(time(NULL));

	for (i = 0; i < number_select; i++)
	{
		check = false;
		index_ar = rand() % size;			// находим случайное число (от 0 до размера массива - 1) 
		if (i == 0)							// если это первая итерация, сохраняем индекс в массив
			temp_ar[i] = index_ar;
		else
		{
			for (j = 0; j < i; j++)			// проверяем, есть ли наше случайное число в массиве выведенных значений
			{
				if (index_ar == temp_ar[j])
					check = true;
			}
		}
		if (check)							// если есть повтор числа, то продолжаем работу цикла на той же итерации
		{									// i-- уменьшит значение, но i++ снова вернет на ту же итерацию
			i--;							// для генерирования случайного числа (индекса массива)
			continue;
		}
		else								// если совпадений нету, выводим значение массива по сгенерированому индексу
		{
			temp_ar[i] = index_ar;
			printf(" %d", ar[index_ar]);
		}
	}
	putchar('\n');
}