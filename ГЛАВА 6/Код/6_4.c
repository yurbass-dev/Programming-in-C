#include <stdio.h>
int main(void)
{
	int i, j;
	char ch;

	ch = 'A' - 1;

	for(i = 0; i < 6; i++)
	{
		for(j = 0; j <= i; j++)
		{
			ch++;
			printf("%c", ch);
		}
		printf("\n");
	}
	return 0;
}