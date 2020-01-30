#include <stdio.h>
int main(void)
{
	int count, sum, day;

	sum = 0;
	count = 0;

	printf("Введите количество дней, для подсчета суммы.\n");
	printf("Для отмены введите 0.\n");
	scanf("%d", &day);

	while (count++ < day)
		sum = sum + count;
	printf("За %d дней Вы получите $%d.\n", day, sum);

	return 0;
}