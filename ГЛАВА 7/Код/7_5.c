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
		switch(ch)
		{
			case DOT : putchar(ZNAK);
					   i++;
					   break;
			case ZNAK : putchar(ZNAK);
						putchar(ZNAK);
						j++;	
						break;
			default : putchar(ch);
		}
	}
	printf("\nБыло заменено %d точек знаком восклицания и %d восклицательных знаков,"
		   " двумя восклицательными знаками.\n", i, j);

	return 0;
}