#include <stdio.h>
int main(void)
{
	char ch = 'a';
	ch--;

	while (ch++ < 'g')
		printf("%5c", ch);
	printf("\n");

	return 0;
}