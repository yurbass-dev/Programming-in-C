#include <stdio.h>
#define SYMBOL '$'
#define ROWS 4
#define DOLLAR 8

int main(void)
{
	int i, row;

	for(row = 0; row < ROWS; row++)
	{
		for(i = 0; i < DOLLAR; i++)
			printf("%c", SYMBOL);
		printf("\n");
	}

	return 0;
}