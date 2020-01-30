#include <stdio.h>

#define HELLO "Hello, world!"

const char * find_first_ch(const char * string, const char ch);

int main(void)
{
	char array[80] = "Hello, how are you?";
	const char * check;

	while ((check = find_first_ch(array, 'h')) == NULL)
	{
		puts("Символ не найден.");
	}
	putchar(*check);
	putchar('\n');

	puts("Программа завершена!");

	return 0;
}


const char * find_first_ch(const char * string, const char ch)
{
	const char * find;

	while (*string != '\0')
	{
		if (*string == ch)
		{
			find = string;
			break;
		}
		else 
		{
			string++;
		}
	}
	if (*string == '\0')
	{
		find = NULL;
	}

	return find;
}