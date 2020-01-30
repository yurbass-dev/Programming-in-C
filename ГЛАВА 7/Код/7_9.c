#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	unsigned long num;
	unsigned long count;
	unsigned long i;
	bool isSimple;

	printf("Введите положительное целое число, чтобы узнать все простые числа,\nкоторые меньше или равно введеному числу:\n");

	 while (scanf("%lu", &num) == 1)
	 {
	 	for (count = 2; num >= count; count++)
	 	{
	 		for (i = 2, isSimple = true; count >= (i * i); i++)
	 		{
	 			if (count % i == 0)
	 				isSimple = false;
	 		}
	 		if (isSimple)
	 			printf("%lu, ", count);
	 	}
	 	printf("\nВведите положительное целое число (или q для завершения): ");
	 }

	printf("Готово!\n");

	return 0;
}