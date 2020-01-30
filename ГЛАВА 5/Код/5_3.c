#include <stdio.h>
#define WEEK 7
int main(void)
{
	int day, week, ost_week;
	printf("Введите количество дней для перевода в недели и дни.\n");
	printf("Для отмены введите 0.\n");
	scanf("%d", &day);
	
	while ( day > 0)
	{
		week = day / WEEK;
		ost_week = day % WEEK;
		printf("%d дней составляют %d недели и %d дня.\n", day, week, ost_week);
		printf("Введите следующее значение или 0 для отмены.\n");
		scanf("%d", &day);
	}
	
	return 0;
}
