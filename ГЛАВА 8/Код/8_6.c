#include <stdio.h>
#include <ctype.h>

char get_first(void);
int main(void)
{
	char ch;

	while ((ch = get_first()) != EOF)
		putchar(ch);
	putchar('\n');
	
	return 0;
}

char get_first(void)
{
	char ch;

	ch = getchar();
	if (isalpha(ch) || ch == EOF)
		return ch;
}