#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

float addition(float , float);
float substraction(float , float);
float multiplication(float, float);
float division(float , float);
void del(void);
void show_menu(void);

int main(void)
{
	// массив указателей на функции которые принимают 2 аргумента 
	// числа с плавающей точкой и возвращают число с плавающей точкой.
	float (*pf[SIZE])(float, float) =
	{
		addition,
		substraction,
		multiplication,
		division
	};		

	float a, b, rezult;
	char choice;

	printf("Введите числа, с которыми хотите совершить арифметические операции.\n");
	printf("Введите первое число: ");
	while (scanf("%f", &a) == 1)
	{	
		del();
		printf("Второе число: ");
		if (scanf("%f", &b) != 1)
			break;
		del();
		show_menu();
		if (scanf("%c", &choice) != 1)
			break;
		del();
		switch (choice)
		{
			case 'a':
				printf("%g.\n", (*pf[0])(a, b));
				break;
			case 'b':
				printf("%g.\n", (*pf[1])(a, b));
				break;
			case 'c':
				printf("%g.\n", (*pf[2])(a, b));
				break;
			case 'd':
				printf("%g.\n", (*pf[3])(a, b));
				break;
			default:
				puts("Ошибка в операторе switch");
				break;
		}
		printf("Для продолжения введите первое число (чтобы выйти введите q): ");
	}

	puts("Программа завершена!");

	return 0;
}

float addition(float a, float b)
{
	printf("Результат сложения чисел %g + %g = ", a, b);
	return a + b;
}

float substraction(float a, float b)
{
	printf("Результат вычитания чисел %g - %g = ", a, b);
	return a - b;
}

float multiplication(float a, float b)
{
	printf("Результат умножения чисел %g * %g = ", a, b);
	return a * b;
}

float division(float a, float b)
{
	if (b == 0.0f)
	{
		printf("Делить на 0 ноль нельзя!\n");
		exit(1);
	}
	printf("Результат деления чисел %g / %g = ", a, b);
	return a / b;
}
void del(void)
{
	while (getchar() != '\n')
		continue;
}

void show_menu(void)
{
	puts("Выберите арифметическую операцию:");
	puts("a) сложение");
	puts("b) вычитание");
	puts("c) умножение");
	puts("d) деление");
}