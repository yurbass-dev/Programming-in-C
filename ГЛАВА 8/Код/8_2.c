#include <stdio.h>

int main(void)
{
	char ch;

	for (int i = 0; (ch = getchar()) != EOF; i++)
	{
		if (i == 10)
		{
			putchar('\n');
			i = 0;
		}

		if (ch == ' ')
			printf("\' \' - %d ", ch);
		else if (ch == '\n')
			printf("\\n - %d ", ch);
		else if (ch == '\t')
			printf("\\t - %d ", ch);
		else 
			printf("%c - %d ", ch, ch);

		

	}

	return 0;
}