#include <stdio.h>
#define STOP '#'

int main(void)
{
	char ch;
	int i = 1;

	printf("Введите данные для перевода каждого символа в "
		   "десятичный код ASCII (# для завершения).\n");

	while ((ch = getchar()) != STOP)
	{
		
		
		printf("%2c-%3d ", ch, ch);
		while (getchar() != '\n')
			continue;
		printf("\n");
		if (i % 8 == 0)
			printf("\n");
		i++;
	}
	printf("\nГотово.\n");

	return 0;
}