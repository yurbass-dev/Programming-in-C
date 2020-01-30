#include <stdio.h>

static int count = 0;

void func(void);

int main(void)
{
	for (int i = 0; i < 20; i++)
		func();
	printf("Количество вызовов функции равно %d.\n", count);

	return 0;
}

void func(void)
{
	count++;
}