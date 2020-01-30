#include <stdio.h>
#define DOT '.'
#define ZNAK '!'
#define STOP '#'

int main(void)
{
	char ch;
	int i = 0;
	int j = 0;

	printf("Введите данные:\n");
	while ((ch = getchar()) != STOP)
	{
		if (ch == DOT)
		{
			putchar(ZNAK);
			i++;
		}
		
		else if (ch == ZNAK)
		{
			putchar(ZNAK);
			putchar(ZNAK);
			j++;
		}
		else
			putchar(ch);
	}
	printf("Было заменено %d точек знаком восклицания и %d восклицательных знаков,"
		   " двумя восклицательными знаками.\n", i, j);

	return 0;
}