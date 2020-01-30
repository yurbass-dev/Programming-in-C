#include <stdio.h>
#define MIN_IN_HOUR 60
int main(void)
{
	int hour, min, ostatok_min;
	printf("Введите количество минут для перевода в часы и минуты.\n");
	printf("Для отмены введите 0.\n");
	scanf("%d", &min);
	
	while (min > 0)
	{
		hour = min / MIN_IN_HOUR;
		ostatok_min = min % MIN_IN_HOUR;
		printf("Вы ввели %d минут, это %d часа и %d минут!\n", min, hour, ostatok_min);
		printf("Для продолжения, введите количество минут или для отмены, введите 0.\n");
		scanf("%d", &min);
	}

	return 0;
}