#include <stdio.h>
#define ARTISHOK 2.05
#define SVEKLA 1.15
#define MORKOV 1.09
#define SKIDKA 0.05			//скидка 5% на заказы на сумму $100 и выше
#define SUM_SKIDKA 100.0	//сумма для получения скидки в 5% от $100 и выше
#define ZATRATI_1 6.50		//затраты за доставку и обработку заказа весом в 5 фунтов и меньше
#define ZATRATI_2 14.0		//затраты за доставку и обработку заказа весом от 5 до 20 фунтов
#define ZATRATI_3 0.50		// $14 плюс $0.50 за каждый фунт за доставку и обработку заказа весом превышающим 20 фунтов

int main(void)
{
	char vubor;
	double all_weigth;
	double weight_artishok = 0.0;
	double artishok;
	double weight_svekla = 0.0;
	double svekla;
	double weight_morkov = 0.0;
	double morkov;
	double all_price;
	double itog_price;
	double skidka = 0.0;
	double zatrati;

	printf("Выберите категория товара, чтобы указать желаемый вес продукта в фунтах:\n");
	printf("a) Артишоки\n");
	printf("b) Свекла\n");
	printf("c) Морковь\n");
	printf("Нажмите q чтобы завершить процесс заказа.\n");

	while ((vubor = getchar()) && vubor != 'q')
	{
		if (vubor == '\n')
			continue;
		switch (vubor)
		{
			case 'a': printf("Введите вес артишоков: ");
				      scanf("%lf", &artishok);
					  weight_artishok += artishok;
					  break;
			case 'b': printf("Введите вес свеклы: "); 
					  scanf("%lf", &svekla);
					  weight_svekla += svekla;
				      break;
			case 'c': printf("Введите вес моркови: ");
					  scanf("%lf", &morkov);
					  weight_morkov += morkov;
				      break;
			default : printf("Выберите верную категорию или q для завершения.\n");
		}
		printf("Чтобы добавить еще овощей, введите а для артишоков, b для свеклы\nи c для моркови.\n");
	}	

	all_price = weight_artishok * ARTISHOK + weight_svekla * SVEKLA + weight_morkov * MORKOV;
	all_weigth = weight_artishok + weight_svekla + weight_morkov;

	if (all_price >= SUM_SKIDKA)
		skidka = all_price * SKIDKA;
	if (all_weigth <= 5)
		zatrati = ZATRATI_1;
	else if (all_weigth > 5 && all_weigth <= 20)
		zatrati = ZATRATI_2;
	else 
		zatrati = ZATRATI_2 + (ZATRATI_3 * all_weigth);

	itog_price = all_price - skidka + zatrati;

	printf("\nСтоимость за фунт артишоков составляет $%.2f, свеклы $%.2f и моркови $%.2f.\n", ARTISHOK, SVEKLA, MORKOV);
	printf("Всего было заказано овощей на %.2f фунтов.\n", all_weigth);
	printf("Стоимость артишоков $%.2f за %.2f фунтов, свеклы $%.2f за %.2f фунтов и"
		   "моркови $%.2f за %.2f фунтов.\n", 
			weight_artishok * ARTISHOK, weight_artishok, weight_svekla * SVEKLA, weight_svekla,
			weight_morkov * MORKOV, weight_morkov);
	printf("Общая стоимость заказа составляет $%.2f.\n", all_price);
	printf("Скидка составляет $%.2f.\n", skidka);
	printf("Доставка обойдется в $%.2f.\n", zatrati);
	printf("Итоговая стоимость составляет $%.2f.\n", itog_price);

	return 0;
}
