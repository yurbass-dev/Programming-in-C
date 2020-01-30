#include <stdio.h>

void one_three(void);
void two(void);

int main(void)
{
	printf("начинаем:\n");
	one_three();
	printf("порядок!\n");

	return 0;
}

// функция выводит "один" в первой строке, вызывает функцию two() 
// и выводит "три" в третей строке.

void one_three(void)
{
	printf("один\n");
	two();
	printf("три\n");
}

// функция выводит "два" во второй строке.

void two(void)
{
	printf("два\n");
}