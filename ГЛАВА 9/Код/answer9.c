#include <stdio.h>
#define LOW 1
#define HIGH 4

void menu(void);
int choise(int, int);

int main(void)
{
	menu();
	printf("Вы выбрали вариант %d.\n", choise(LOW, HIGH));
}

void menu(void)
{
	printf("Выберите одиз из следующих вариантов:\n");
	printf("1) копировать файлы      2) переместить файлы\n");
	printf("3) удалить файлы         4) выйти из программы\n");
	printf("Введите номер выбраного варианта: ");
}

int choise(int low, int high)
{
	int status;
	float num;
	float num_2;
	int num_1;
	int temp = HIGH;

	while (status = scanf("%f", &num))
	{
		printf("%d\n", status);
		if (status != 1)
		{
			scanf("%*s");
			continue;
		}	
		num_1 = num;
		num_2 = num - num_1;

		if (num_2 > 0)
			temp = high;
		else if ((int) num < low || (int) num > high)
		{
			menu();
			continue;
		}
		else
			temp = (int) num;
	}
	return temp;
}