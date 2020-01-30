#include <stdio.h>

int main(void)
{
	int count = 0;
	char ch;

	while ((ch = getchar()) != EOF)
		count++;

	printf("В файле %d символов.\n", count);

	return 0;
}