#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *src;
	FILE *dest;
	int num_ar[20][30];
	char symb_ar[20][31];
	char f_name1[31];
	char f_name2[31];
	int index = 0;
	char symbols[10] = {' ', '.', '^', ':', '~', '*', '=', '+', '%', '#'};

	printf("Введите имя файла, значение которого нужно считать:\n");
	scanf("%s", f_name1);

	if ((src = fopen(f_name1, "r")) == NULL)
	{
		fprintf(stderr, "Не удалось открыть файл %s.\n", f_name1);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 20 && !feof(src); i++)
	{
		for (int j = 0; j < 30; j++)
		{
			fscanf(src, "%d", &num_ar[i][j]);
		}
	}

	printf("Введите имя файла, куда хотите сохранить значения:\n");
	scanf("%s", f_name2);
	putchar('\n');

	if ((dest = fopen(f_name2, "w")) == NULL)
	{
		fprintf(stderr, "Не удалось открыть файл %s.\n", f_name2);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			if (j == 30)
			{
				symb_ar[i][j] = '\0';
			}
			else
			{
				index = num_ar[i][j];
				symb_ar[i][j] = symbols[index];
			}

		}
	}

	for (int i = 0; i < 20; i++)
	{
		puts(symb_ar[i]);
		fprintf(dest, "%s\n", symb_ar[i]);

	}

	if (fclose(src) != 0)
	{
		fprintf(stderr, "Не удалось закрыть файл %s.\n", f_name1);
	}
	if (fclose(dest) != 0)
	{
		fprintf(stderr, "Не удалось закрыть файл %s.\n", f_name2);
	}
	putchar('\n');
	puts("Программа завершена!");

	return 0;
}