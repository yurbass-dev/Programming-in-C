#include <stdio.h>
#include <ctype.h>

#define SIZE 40

char * save_first_word(char * arr, int size);

int main(void)
{
	char array[SIZE];
	char * check;

	puts("Введите строку.");
	check = save_first_word(array, 5);
	if (check)
		puts(array);
	else		
		puts("Допущена ошибка. Введите строку повторно.");
	puts("Программа завершена!");

	return 0;
}

char * save_first_word(char * arr, int size)
{
	char ch;
	char prev;
	char * check = arr;

	for (int i = 0; i < size && (ch = getchar()) != EOF; )
	{
		if (isalpha(ch))
		{
			*arr++ = ch;
			prev = ch;
			i++;
		}
		else if (isalpha(ch) && !isalpha(prev))
		{
			*arr = '\0';
			break;
		}
		else if (!isalpha(ch))
		{
			prev = ch;
			continue;
		}
	}
	if (ch == EOF)
		check = NULL;

	return check;
}