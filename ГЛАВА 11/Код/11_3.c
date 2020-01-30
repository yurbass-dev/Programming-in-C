#include <stdio.h>
#include <ctype.h>

#define SIZE 40

char * save_first_word(char * arr);

int main(void)
{
	char array[SIZE];
	char * check;

	puts("Введите строку.");
	check = save_first_word(array);
	if (check)
		puts(array);
	else		
		puts("Допущена ошибка. Введите строку повторно.");
	puts("Программа завершена!");

	return 0;
}

char * save_first_word(char * arr)
{
	char ch;
	char prev;
	char * check = arr;

	while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch))
		{
			*arr++ = ch;
			prev = ch;
		}
		else if (isspace(ch) && isalpha(prev))
		{
			*arr = '\0';
			break;
		}
		else if (isspace(ch))
		{
			prev = ch;
			continue;
		}
	}
	if (ch == EOF)
		check = NULL;

	return check;
}