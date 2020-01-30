#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define COUNT_STR 10
#define SIZE_STR 81

void show_menu(void);
char * s_gets(char * string, int size);
void str_ASCII(char * str[], int ct_str);
void length_str(char * str[], int ct_str);
void length_word_str(char * str[], int ct_str);

int main(void)
{
	char array_str[COUNT_STR][SIZE_STR];
	char * pt_str[COUNT_STR];
	int choise;
	int ct_str = 0;

	puts("Введите до 10 строк размером до 80 символов:");
	while(ct_str < COUNT_STR && s_gets(array_str[ct_str], SIZE_STR) != NULL && array_str[ct_str][0] != '\0')
	{
		pt_str[ct_str] = array_str[ct_str]; 
		ct_str++;
	}

	do
	{
		show_menu();
		scanf("%d", &choise);
		switch (choise)
		{
			case 1:
			{
				puts("Исходный список строк:");
				for (int j = 0; j < ct_str; j++)
					puts(array_str[j]);
				break;
			}
			case 2:
			{
				str_ASCII(pt_str, ct_str);
				for (int i = 0; i < ct_str; i++)
					puts(pt_str[i]);
				break;
			}
			case 3:
			{
				length_str(pt_str, ct_str);
				for (int i = 0; i < ct_str; i++)
					puts(pt_str[i]);
				break;
			}
			case 4:
			{
				length_word_str(pt_str, ct_str);
				for (int i = 0; i < ct_str; i++)
					puts(pt_str[i]);
				break;
			}
			case 5:
			{
				puts("Программа завершена.");
				break;
			}
			default:
			{
				puts("Введите цифру от 1 до 5.");
				break;
			}
		}
	}
	while (choise != 5);
	
	return 0;
}


void show_menu(void)
{
	printf("------------------------------------------------------------------\n");
	printf("Выберите один из пяти вариантов:\n");
	printf("1) Вывод исходного списка строк.\n");
	printf("2) Вывод строк согласно последовательности сопоставления ASCII.\n");
	printf("3) Вывод строк в порядке возростания длины.\n");
	printf("4) Вывод строк в порядке возростания длины первого слова в строке.\n");
	printf("5) Выход.\n");
	printf("------------------------------------------------------------------\n");
}

void length_word_str(char * str[], int ct_str)
{
	char * temp;
	int i, j;
	int size_word_1 = 0;
	int size_word_2 = 0;


	for (i = 0; i < ct_str - 1; i++)
	{	
		for (j = i + 1; j < ct_str; j++)
		{
			while (!isspace(str[i][size_word_1]) && !ispunct(str[i][size_word_1]) && str[i][size_word_1] != '\0')
			{
				size_word_1++;
			}
			while (!isspace(str[j][size_word_2]) && !ispunct(str[j][size_word_2]) && str[j][size_word_2] != '\0')
			{
				size_word_2++;
			}
			if (size_word_1 > size_word_2)
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
			size_word_1 = 0;
			size_word_2 = 0;
		}
	}
}

void length_str(char * str[], int ct_str)
{
	char * temp;
	int i, j;

	for (i = 0; i < ct_str - 1; i++)
	{
		for (j = i + 1; j < ct_str; j++)
		{
			if (strlen(str[i]) > strlen(str[j]))
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}

		}
	}

}

void str_ASCII(char * str[], int ct_str)
{
	char * temp;
	int i, j;

	for (i = 0; i < ct_str - 1; i++)
	{
		for (j = i + 1; j < ct_str; j++)
		{
			if (strcmp(str[i], str[j]) > 0)
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}

		}
	}
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

