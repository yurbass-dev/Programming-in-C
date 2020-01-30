#include <stdio.h>
#include <string.h>

#define SIZE 80

char * reverse_string(char * str);
char * s_gets(char * string, int size);

int main(void)
{
	char * check = NULL;
	char string[SIZE];

	puts("Введите строку для того, чтобы получить ее в обратном порядке:");
	while ((check = s_gets(string, SIZE)) && *string != '\0')
	{
		if ((check = reverse_string(string)))
		{
			puts(string);
		}
		puts("Введите следующую строку или клавишу Enter для выхода.");
	}
	if (check)
		puts("Ошибка!");

	puts("Программа завершена.");

	return 0;
}

char * reverse_string(char * str)
{
	char * check = NULL;
	char temp_str[SIZE];
	int size_s = strlen(str);

	if (str)
	{
		for (int ch = 0; ch < size_s; ch++)
		{
			temp_str[ch] = str[ch]; 
		}
		for (int up = 0, down = size_s - 1; up < size_s; up++, down--)
		{
			str[up] = temp_str[down]; 
		}
		check = str;
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