#include <stdio.h>

#define SIZE 80

char * del_space(char * str);
char * s_gets(char * string, int size);

int main(void)
{
	char string[SIZE];

	puts("Введите строку и увидите как из нее пропадут все символы пробела:");
	while (s_gets(string, SIZE) && *string != '\0')
	{
		del_space(string);
		puts(string);
		puts("Введите следующую строку (или нажмите клавишу Enter для завершения):");
	}
	puts("Программа завершена.");

	return 0;
}


char * del_space(char * str)
{
	char * check = NULL;
	int i = 0;

	if (str)
	{
		while (str[i] != '\0')
		{
			if (str[i] == ' ')
			{
				for (int j = i, k = i + 1; str[j] != '\0'; j++, k++)
				{
					str[j] = str[k];
				}
			}
			else
				i++;
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