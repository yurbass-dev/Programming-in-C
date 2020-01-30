#include <stdio.h>
#define STOP '#'

int main(void)
{
	char ch;
	char prev;
	int zamen = 0;

	printf("Введите данные:\n");
	while ((ch = getchar()) != STOP)
	{
		if (ch == 'e')
			prev = ch;
		else if (ch != 'i')
			prev = ch;
		if (prev == 'e' && ch == 'i')
			zamen++;
	}
	printf("Количество вхождений последовательности \"ei\" составляет %d раз.\n", zamen);

	return 0;
}