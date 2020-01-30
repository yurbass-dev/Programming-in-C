#include <stdio.h>
#include <ctype.h>

#define SIZE 81

int digit(char * str, int size);
char * s_gets(char * string, int size);

int main(void)
{
	char string[SIZE];

	if (s_gets(string, SIZE))
	{
		if (digit(string, SIZE))
			puts(string);
		else
			puts("Строка не полностью числовая!");
	}
	puts("Завершение программы.");

	return 0;
}

int digit(char * str, int size)
{
	int check = 1;

	while (*str != '\0')
	{
		if (!isdigit(*str))
		{
			check = 0;
			break;
		}
		str++;
	}

	return check;
}

char * s_gets(char * string, int size)
{
	char * check;

	check = fgets(string, size, stdin);

	if (check)
	{
		while (*string != '\n' && *string != '\0')
			string++;
		if (*string == '\n')
			*string = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return check;
}