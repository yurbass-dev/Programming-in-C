#include <stdio.h>
#include <stdlib.h> 			// для функции strtol()
#include <string.h>				// для ф-ции strchr()
#define SIZE 33

char * s_gets(char * st, int n);

int main(void)
{
	char str[SIZE];
	int i;
	bool check = false;

	puts("Введите двоичное число для перевода в десятичное: ");
	while (s_gets(str, SIZE) != NULL && str[0] != '\0')
	{ 
		i = 0;
		check = false;
		while (str[i] != '\0')
		{
			if (str[i] != '0' && str[i] != '1')
			{
				puts("Нужно вводить число состоящее только из 0 и 1.");
				check = true;
			}
			i++;
		}
		if (check)
		{
			puts("Введите двоичное число для перевода в десятичное: ");
			continue;
		}
		printf("Число 0b%s = %ld в десятичной форме.\n", str, strtol(str, NULL, 2));
		puts("Введите следующее число или 'enter' для выхода: ");
	}

	puts("Программа завершена!");

	return 0;
}

char * s_gets(char * st, int n) 
{
	char * ret_val; 
	char * find;
	ret_val = fgets(st, n, stdin); 
	if (ret_val)
	{
		find = strchr(st, '\n'); 
		if (find)
			*find = '\0'; 
		else
			while (getchar() != '\n') 
				continue;
	}
	return ret_val;
}