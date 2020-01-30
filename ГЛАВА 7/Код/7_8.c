#include <stdio.h>
#define STAVKA_1 8.75
#define STAVKA_2 9.33
#define STAVKA_3 10.0
#define STAVKA_4 11.20
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
	double nalog;
	double stavka;
	int switch_stavka;

	printf("*********************************************************************\n");
	printf("Введите число, соответствующее желаемой тарифной ставке или действию:\n");
	printf("1) $%.2f/ч                     2) $%.2f/ч\n", STAVKA_1, STAVKA_2);
	printf("3) $%.2f/ч                    4) $%.2f/ч\n", STAVKA_3, STAVKA_4);
	printf("5) Выход\n");
	printf("*********************************************************************\n");

	scanf("%d", &switch_stavka);

	while (switch_stavka != 5)
	{
		switch(switch_stavka)
		{
			case 1: stavka = STAVKA_1;
				break;
			case 2: stavka = STAVKA_2;
				break;
			case 3: stavka = STAVKA_3;
				break;
			case 4: stavka = STAVKA_4;
				break;
		}

		if (switch_stavka >= 1 && switch_stavka <= 4)
		{
			printf("Введите количество отработанных часов за неделю: ");
			scanf("%lf", &hours);

			if (hours <= HOURS)
				dirt_sum = hours * stavka;
			else
				dirt_sum = (HOURS * stavka) + ((hours - HOURS) * (OVER * stavka));

			if (dirt_sum <= RATE_1)
			{
				nalog = dirt_sum * NALOG_1;
				clear_sum = dirt_sum - nalog;
			}
			else if (dirt_sum > RATE_1 && dirt_sum <= RATE_2)
			{
				nalog = ((dirt_sum - RATE_1) * NALOG_2) + (RATE_1 * NALOG_1);
				clear_sum = dirt_sum - nalog;
			}
			else
			{
				nalog = ((dirt_sum - RATE_1) - (RATE_2 - RATE_1)) * NALOG_3 + (RATE_1 * NALOG_1) + ((RATE_2 - RATE_1) * NALOG_2);
				clear_sum = dirt_sum - nalog;
			}
		
			printf("\nОбщая сумма начислений $%.2f.\n", dirt_sum);
			printf("Налоги $%.2f.\n", nalog);
			printf("Чистая зарплата составляет $%.2f.\n\n", clear_sum);

			printf("Введите число, соответствующее желаемой тарифной ставке или действию "
				   "\n(5 для выхода):\n");
			scanf("%d", &switch_stavka);
			continue;
		}

		if (switch_stavka < 1 || switch_stavka > 5)
		{
			printf("*********************************************************************\n");
			printf("Введите число, соответствующее желаемой тарифной ставке или действию:\n");
			printf("1) $%.2f/ч                     2) $%.2f/ч\n", STAVKA_1, STAVKA_2);
			printf("3) $%.2f/ч                    4) $%.2f/ч\n", STAVKA_3, STAVKA_4);
			printf("5) Выход\n");
			printf("*********************************************************************\n");

			scanf("%d", &switch_stavka);
			continue;
		}
	}
	
	return 0;
}