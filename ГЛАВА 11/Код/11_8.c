#include <stdio.h>
#include <string.h>

#define SIZE 80

char * s_gets(char * string, int size);
const char * string_in(const char * string_1, const char * string_2);

int main(void)
{
	const char * check;
	char array[SIZE];
	char array_2[SIZE];

	puts("Введите первую строку:");	
	while ((check = s_gets(array, SIZE)) && *array != '\0')
	{
		puts("Введите слово или символы, которые хотите найти в первой строке:");
		if ((check = s_gets(array_2, SIZE)) && *array_2 != '\0')
		{
			if ((check = string_in(array, array_2)))
			{
				puts("Есть совпадение!");
				puts(check);
			}
		}
		puts("Введите первую строку:");
	}
	if (check)
		puts("Ошибка.");

	puts("Программа завершена.");

	return 0;
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


const char * string_in(const char * string_1, const char * string_2)
{
	int size_ch = 0;
	const char * find = NULL;

	if (string_1 != NULL && string_2 != NULL)
	{
		size_ch = strlen(string_2);

		while (*string_1 != '\0')
		{
			if (*string_1 == *string_2)
			{	
				for (int ch = 0, count_ch = 0; ch < size_ch; ch++)
				{
					if (string_1[ch] == string_2[ch])
						count_ch++;
					if (count_ch == size_ch)
					{
						find = string_1;
						break;
					}
				}
				if (find)
					break;
				string_1++;
			}
			else
				string_1++;
		}
	}

	return find;
}