#include <stdio.h>

#define HELLO "Hello, world!"

int is_within(const char * string, char ch);

int main(void)
{
	char array[80] = "Hello, how are you?";

	if (is_within(HELLO, 'w'))
		puts("Символ есть в строке.");
	else
		puts("Символ отсутсвует в строке.");

	puts("Программа завершена.");

	return 0;
}

int is_within(const char * string, char ch)
{
	int value;

	while (*string != '\0')
	{
		if (*string == ch)
		{
			value = 1;
			break;
		}
		else 
			value = 0;
		string++;
	}

	return value;
}