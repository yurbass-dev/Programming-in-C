#include <stdio.h>
#define NALOG_1 0.15
#define NALOG_2 0.28
#define CATEGORY_1 17850.0
#define CATEGORY_2 23900.0
#define CATEGORY_3 29750.0
#define CATEGORY_4 14875.0


int main(void)
{
	int category;
	double all_sum;
	
	printf("----------------------------------------------------------------------------\n");
	printf("   Категория                       Налог\n");
	printf("----------------------------------------------------------------------------\n");
	printf("1) Одинокий                        %0.f%% с первых $%0.f плюс %0.f%% от суммы,\n"
		   "                                   превышающей указанную\n\n", NALOG_1 * 100.0, CATEGORY_1, NALOG_2 * 100.0);
	printf("2) Глава семейства                 %0.f%% с первых $%0.f плюс %0.f%% от суммы,\n"
		   "                                   превышающей указанную\n\n", NALOG_1 * 100.0, CATEGORY_2, NALOG_2 * 100.0); 
	printf("3) Состоит в браке, совместное     %0.f%% с первых $%0.f плюс %0.f%% от суммы,\n"
		   "   ведение хозяйства               превышающей указанную\n\n", NALOG_1 * 100.0, CATEGORY_3, NALOG_2 * 100.0);
	printf("4) Состоит в браке, раздельное     %0.f%% с первых $%0.f плюс %0.f%% от суммы,\n"
		   "   ведение хозяйства               превышающей указанную\n", NALOG_1 * 100.0, CATEGORY_4, NALOG_2 * 100.0);
	printf("----------------------------------------------------------------------------\n\n");

	printf("Выбирете и введите категорию и облагаемый налогом доход: \n");
	while (scanf("%d %lf", &category, &all_sum) == 2)
	{
		switch (category)
		{
			case 1: 
					if (all_sum <= CATEGORY_1)
						printf("Из введенной суммы $%.2lf, получается $%.2lf налогов.\n", all_sum, all_sum * NALOG_1);
					else
						printf("Из введенной суммы $%.2lf, получается $%.2lf налогов.\n", 
								all_sum, (NALOG_1 * CATEGORY_1 + NALOG_2 * (all_sum - CATEGORY_1)));
					break;
			case 2:
					if (all_sum <= CATEGORY_2)
						printf("Из введенной суммы $%.2lf, получается $%.2lf налогов.\n", all_sum, all_sum * NALOG_1); 
					else
						printf("Из введенной суммы $%.2lf, получается $%.2lf налогов.\n", 
							all_sum, (NALOG_1 * CATEGORY_2 + NALOG_2 * (all_sum - CATEGORY_2)));
					break;
			case 3: 
					if (all_sum <= CATEGORY_3)
						printf("Из введенной суммы $%.2lf, получается $%.2lf налогов.\n", all_sum, all_sum * NALOG_1); 
					else
						printf("Из введенной суммы $%.2lf, получается $%.2lf налогов.\n", 
							all_sum, (NALOG_1 * CATEGORY_3 + NALOG_2 * (all_sum - CATEGORY_3)));
					break;
			case 4: 
					if (all_sum <= CATEGORY_4)
						printf("Из введенной суммы $%.2lf, получается $%.2lf налогов.\n", all_sum, all_sum * NALOG_1);
					else
						printf("Из введенной суммы $%.2lf, получается $%.2lf налогов.\n", 
							all_sum, (NALOG_1 * CATEGORY_4 + NALOG_2 * (all_sum - CATEGORY_4)));
					break;
			default: 
					printf("Выбирете верную категорию!\n");
					break;
		}

		printf("Для выхода введите q\n");
	}


	return 0;
}