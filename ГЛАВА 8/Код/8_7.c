#include <stdio.h>
#include <ctype.h>
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
	char switch_stavka;

	printf("*********************************************************************\n");
	printf("Введите букву, соответствующую желаемой тарифной ставке или действию:\n");
	printf("a) $%.2f/ч                     b) $%.2f/ч\n", STAVKA_1, STAVKA_2);
	printf("c) $%.2f/ч                    d) $%.2f/ч\n", STAVKA_3, STAVKA_4);
	printf("q) Выход\n");
	printf("*********************************************************************\n");

	switch_stavka = getchar();

	while (getchar() != '\n')
		continue;

	while (switch_stavka != 'q')
	{
		switch(switch_stavka)
		{
			case 'a': stavka = STAVKA_1;
				break;
			case 'b': stavka = STAVKA_2;
				break;
			case 'c': stavka = STAVKA_3;
				break;
			case 'd': stavka = STAVKA_4;
				break;
		}

		if (switch_stavka == 'a' || switch_stavka == 'b' || switch_stavka == 'c' || switch_stavka == 'd')
		{
			printf("Введите количество отработанных часов за неделю: ");
			
			while (scanf("%lf", &hours) != 1)
			{
				while (getchar() != '\n')
					continue;
				printf("Введите количество отработанных часов за неделю цифрами: ");
			}
			while (getchar() != '\n')
				continue;

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
			printf("Введите букву, соответствующую желаемой тарифной ставке или действию "
				   "\n(q для выхода):\n");
			switch_stavka = getchar();
			continue;
		}

		if (switch_stavka != 'a' || switch_stavka != 'b' || switch_stavka != 'c' || switch_stavka != 'd')
		{
			printf("*********************************************************************\n");
			printf("Введите букву, соответствующую желаемой тарифной ставке или действию:\n");
			printf("a) $%.2f/ч                     b) $%.2f/ч\n", STAVKA_1, STAVKA_2);
			printf("c) $%.2f/ч                    d) $%.2f/ч\n", STAVKA_3, STAVKA_4);
			printf("q) Выход\n");
			printf("*********************************************************************\n");

			switch_stavka = getchar();
			while (getchar() != '\n')
				continue;
			continue;
		}
	}
	
	return 0;
}