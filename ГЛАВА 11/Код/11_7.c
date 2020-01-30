#include <stdio.h>

#define SIZE 80

char * s_gets(char * array, int size);
char * mystrncpy(char * string_1, const char * string_2, int n);

int main(void)
{
	char array[SIZE];
	char array_2[SIZE];
	int n;
	char * check = NULL;

	puts("Введите первую строку:");	
	while ((check = s_gets(array, SIZE)) && *array != '\0')
	{
		puts("Введите вторую строку:");
		if ((check = s_gets(array_2, SIZE)) && *array_2 != '\0')
		{
			puts("Введите количество символов, которые нужно скопировать:");
			scanf("%d",&n);
			while (getchar() != '\n')
				continue;
			if ((check = mystrncpy(array, array_2, n)))
				puts(array);
		}
		puts("Введите первую строку:");
	}
	if (check)
		puts("Ошибка.");

	puts("Программа завершена.");

	return 0;
}

char * mystrncpy(char * string_1, const char * string_2, int n)
{
	char * check = string_1;

	if (check)
	{
		while (*string_1 != '\0')
			string_1++;
		if (string_2)
		{
			for (int i = 0; i < n; i++)
			{
				if (*string_2 != '\0')
				{
					*string_1 = *string_2;
					string_2++;
				}
				else
				{
					*string_1 = '\0';
				}
				string_1++;
			}
			*++string_1 = '\0';
		}
		else
			check = NULL;
	}
	else
		check = NULL;

	return check;
}


char * s_gets(char * array, int n)
{
	char * check;

	check = fgets(array, n, stdin);

	if (check)
	{	
		while (*array != '\n' && *array != '\0')
			array++;
		if (*array == '\n')
			*array = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	
	return check;
}

