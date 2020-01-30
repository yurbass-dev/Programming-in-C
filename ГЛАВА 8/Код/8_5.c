#include <stdio.h>

int main(void)
{
	int num = 50;
	char response;
	int high = 100;
	int low = 1;


	printf("Выберите целое число в интервале от 1 до 100. Я попробую угадать "
		   "его.\nНажмите клавишу у, если моя догадка верна, клавишу h,\n"
		   "если ваше число больше и клавишу l, если ваше число меньше.\n");
	printf("Вашим числом является %d?\n", num);

	while ((response = getchar()) != 'y')
	{
		if (response != 'h' && response != 'l')
			printf("Введите y, h или l.\n");
		if (response == 'h')
			low = num + 1;
		else if (response == 'l')
			high = num - 1;
		num = (high + low) / 2; 
		while (getchar() != '\n')
			continue;
		printf("Ладно, тогда это %d.\n", num);
	}
	printf("Готово!\n");

	return 0;
}