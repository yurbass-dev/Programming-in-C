#include <stdio.h>

void chline(char, int, int);

int main(void)
{
	char ch = 'g';
	chline(ch, 1, 10);

	return 0;
}

void chline(char ch, int i, int j)
{
	for (; i < j + 1; i++)
	{
		putchar(ch);
	}
	putchar('\n');
}