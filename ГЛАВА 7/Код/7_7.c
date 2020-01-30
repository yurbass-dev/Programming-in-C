#include <stdio.h>
#define STAVKA 10.0
#define OVER 1.5
#define NALOG_1 0.15
#define NALOG_2 0.20
#define NALOG_3 0.25
#define RATE_1 300.0
#define RATE_2 450.0
#define HOURS 40

int main(void)
{
	double dirt_sum;
	double clear_sum;
	double hours;
	double nalog_1, nalog_2, nalog_3;

	printf("Введите количество отработанных часов за неделю: ");
	scanf("%lf", &hours);

		if (hours <= HOURS)
			dirt_sum = hours * STAVKA;
		else
			dirt_sum = (HOURS * STAVKA) + ((hours - HOURS) * (OVER * STAVKA));

		if (dirt_sum <= RATE_1)
		{
			nalog_1 = dirt_sum * NALOG_1;
			clear_sum = dirt_sum - nalog_1;
		}
		else if (dirt_sum > RATE_1 && dirt_sum <= RATE_2)
		{
			nalog_2 = ((dirt_sum - RATE_1) * NALOG_2) + (RATE_1 * NALOG_1);
			clear_sum = dirt_sum - nalog_2;
		}
		else
		{
			nalog_3 = ((dirt_sum - RATE_1) - (RATE_2 - RATE_1)) * NALOG_3 + (RATE_1 * NALOG_1) + ((RATE_2 - RATE_1) * NALOG_2);
			clear_sum = dirt_sum - nalog_3;
		}
	
	printf("\nОбщая сумма начислений $%g.\n", dirt_sum);

	if (dirt_sum <= RATE_1)		
		printf("Налоги $%g.\n", nalog_1);
	else if (dirt_sum > RATE_1 && dirt_sum <= RATE_2)
		printf("Налоги $%g.\n", nalog_2);
	else
		printf("Налоги $%g.\n", nalog_3);

	printf("Чистая зарплата составляет $%g.\n", clear_sum);

	return 0;
}