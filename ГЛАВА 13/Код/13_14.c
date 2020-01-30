#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 20
#define COLS 30

int main(void)
{
	FILE *src;
	FILE *dest;
	int check = 0;
	int num_ar[ROWS][COLS];
	int num_average_ar[ROWS][COLS];
	char symb_ar[ROWS][COLS + 1];
	char f_name1[81];
	char f_name2[81];
	char symbols[10] = {' ', '.', '^', ':', '~', '*', '=', '+', '%', '#'};

	printf("Введите имя файла, значение которого нужно считать:\n");
	scanf("%s", f_name1);

	if ((src = fopen(f_name1, "r")) == NULL)
	{
		fprintf(stderr, "Не удалось открыть файл %s.\n", f_name1);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < ROWS && !feof(src); i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			fscanf(src, "%d", &num_ar[i][j]);
		}
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (i == 0 && j == 0)
			{
				if (num_ar[i][j] > num_ar[i][j + 1])
				{
					if ((num_ar[i][j] - num_ar[i][j + 1]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i][j + 1])
				{
					if ((num_ar[i][j + 1] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (num_ar[i][j] > num_ar[i + 1][j])
				{
					if ((num_ar[i][j] - num_ar[i + 1][j]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i + 1][j])
				{
					if ((num_ar[i][j + 1] - num_ar[i + 1][j]) > 1)
						check = 1;
				}
				if (check == 1)
				{
					num_average_ar[i][j] = floor((num_ar[i][j + 1] + num_ar[i + 1][j]) / 2);
					check = 0;
				}
				else
				{
					num_average_ar[i][j] = num_ar[i][j];
					check = 0;
				}

			}
			else if (i == 0 && j == COLS - 1)
			{
				if (num_ar[i][j] > num_ar[i][j - 1])
				{
					if ((num_ar[i][j] - num_ar[i][j - 1]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i][j - 1])
				{
					if ((num_ar[i][j - 1] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (num_ar[i][j] > num_ar[i + 1][j])
				{
					if ((num_ar[i][j] - num_ar[i + 1][j]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i + 1][j])
				{
					if ((num_ar[i][j + 1] - num_ar[i + 1][j]) > 1)
						check = 1;
				}
				if (check == 1)
				{
					num_average_ar[i][j] = floor((num_ar[i][j - 1] + num_ar[i + 1][j]) / 2);
					check = 0;
				}
				else
				{
					num_average_ar[i][j] = num_ar[i][j];
					check = 0;
				}
			}
			else if (i == ROWS - 1 && j == 0)
			{
				if (num_ar[i][j] > num_ar[i][j + 1])
				{
					if ((num_ar[i][j] - num_ar[i][j + 1]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i][j + 1])
				{
					if ((num_ar[i][j + 1] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (num_ar[i][j] > num_ar[i - 1][j])
				{
					if ((num_ar[i][j] - num_ar[i - 1][j]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i - 1][j])
				{
					if ((num_ar[i - 1][j] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (check == 1)
				{
					num_average_ar[i][j] = floor((num_ar[i][j + 1] + num_ar[i - 1][j]) / 2);
					check = 0;
				}
				else
				{
					num_average_ar[i][j] = num_ar[i][j];
					check = 0;
				}
			}
			else if (i == ROWS - 1 && j == COLS - 1)
			{
				if (num_ar[i][j] > num_ar[i][j - 1])
				{
					if ((num_ar[i][j] - num_ar[i][j - 1]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i][j - 1])
				{
					if ((num_ar[i][j - 1] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (num_ar[i][j] > num_ar[i - 1][j])
				{
					if ((num_ar[i][j] - num_ar[i - 1][j]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i - 1][j])
				{
					if ((num_ar[i - 1][j] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (check == 1)
				{
					num_average_ar[i][j] = floor((num_ar[i][j - 1] + num_ar[i - 1][j]) / 2);
					check = 0;
				}
				else
				{
					num_average_ar[i][j] = num_ar[i][j];
					check = 0;
				}
			}
			else if (i == 0)
			{
				if (num_ar[i][j] > num_ar[i][j - 1])
				{
					if ((num_ar[i][j] - num_ar[i][j - 1]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i][j - 1]) 
				{
					if ((num_ar[i][j - 1] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (num_ar[i][j] > num_ar[i][j + 1])
				{
					if ((num_ar[i][j] - num_ar[i][j + 1]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i][j + 1])
				{
					if ((num_ar[i][j + 1] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (num_ar[i][j] > num_ar[i + 1][j])
				{
					if ((num_ar[i][j] - num_ar[i + 1][j]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i + 1][j])
				{
					if ((num_ar[i + 1][j] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (check == 1)
				{
					num_average_ar[i][j] = floor((num_ar[i][j - 1] + num_ar[i][j + 1] + num_ar[i + 1][j]) / 3);
					check = 0;
				}
				else
				{
					num_average_ar[i][j] = num_ar[i][j];
					check = 0;
				}
			}
			else if (j == 0)
			{
				if (num_ar[i][j] > num_ar[i][j + 1])
				{
					if ((num_ar[i][j] - num_ar[i][j + 1]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i][j + 1]) 
				{
					if ((num_ar[i][j + 1] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (num_ar[i][j] > num_ar[i - 1][j])
				{
					if ((num_ar[i][j] - num_ar[i - 1][j]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i - 1][j])
				{
					if ((num_ar[i - 1][j] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (num_ar[i][j] > num_ar[i + 1][j])
				{
					if ((num_ar[i][j] - num_ar[i + 1][j]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i + 1][j])
				{
					if ((num_ar[i + 1][j] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (check == 1)
				{
					num_average_ar[i][j] = floor((num_ar[i][j + 1] + num_ar[i - 1][j] + num_ar[i + 1][j]) / 3);
					check = 0;
				}
				else
				{
					num_average_ar[i][j] = num_ar[i][j];
					check = 0;
				}

			}
			else if (i == ROWS - 1)
			{
				if (num_ar[i][j] > num_ar[i][j - 1])
				{
					if ((num_ar[i][j] - num_ar[i][j - 1]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i][j - 1]) 
				{
					if ((num_ar[i][j - 1] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (num_ar[i][j] > num_ar[i - 1][j])
				{
					if ((num_ar[i][j] - num_ar[i - 1][j]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i - 1][j])
				{
					if ((num_ar[i - 1][j] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (num_ar[i][j] > num_ar[i][j + 1])
				{
					if ((num_ar[i][j] - num_ar[i][j + 1]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i][j + 1])
				{
					if ((num_ar[i][j + 1] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (check == 1)
				{
					num_average_ar[i][j] = floor((num_ar[i][j - 1] + num_ar[i - 1][j] + num_ar[i][j + 1]) / 3);
					check = 0;
				}
				else
				{
					num_average_ar[i][j] = num_ar[i][j];
					check = 0;
				}
			}
			else if (j == COLS - 1)
			{
				if (num_ar[i][j] > num_ar[i][j - 1])
				{
					if ((num_ar[i][j] - num_ar[i][j - 1]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i][j - 1]) 
				{
					if ((num_ar[i][j - 1] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (num_ar[i][j] > num_ar[i - 1][j])
				{
					if ((num_ar[i][j] - num_ar[i - 1][j]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i - 1][j])
				{
					if ((num_ar[i - 1][j] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (num_ar[i][j] > num_ar[i + 1][j])
				{
					if ((num_ar[i][j] - num_ar[i + 1][j]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i + 1][j])
				{
					if ((num_ar[i + 1][j] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (check == 1)
				{
					num_average_ar[i][j] = floor((num_ar[i][j - 1] + num_ar[i - 1][j] + num_ar[i + 1][j]) / 3);
					check = 0;
				}
				else
				{
					num_average_ar[i][j] = num_ar[i][j];
					check = 0;
				}
			}
			else
			{
				if (num_ar[i][j] > num_ar[i][j - 1])
				{
					if ((num_ar[i][j] - num_ar[i][j - 1]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i][j - 1]) 
				{
					if ((num_ar[i][j - 1] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (num_ar[i][j] > num_ar[i][j + 1])
				{
					if ((num_ar[i][j] - num_ar[i][j + 1]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i][j + 1])
				{
					if ((num_ar[i][j + 1] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (num_ar[i][j] > num_ar[i + 1][j])
				{
					if ((num_ar[i][j] - num_ar[i + 1][j]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i + 1][j])
				{
					if ((num_ar[i + 1][j] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (num_ar[i][j] > num_ar[i - 1][j])
				{
					if ((num_ar[i][j] - num_ar[i - 1][j]) > 1)
						check = 1;
				}
				else if (num_ar[i][j] < num_ar[i - 1][j])
				{
					if ((num_ar[i - 1][j] - num_ar[i][j]) > 1)
						check = 1;
				}
				if (check == 1)
				{
					num_average_ar[i][j] = floor((num_ar[i][j - 1] + num_ar[i - 1][j] + num_ar[i + 1][j] + num_ar[i][j + 1]) / 4);
					check = 0;
				}
				else
				{
					num_average_ar[i][j] = num_ar[i][j];
					check = 0;
				}
			}

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

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS + 1; j++)
		{
			if (j == COLS)
			{
				putchar('\n');
			}
			else
			{
				printf("%d ", num_average_ar[i][j]);
			}
			if (j == COLS)
			{
				symb_ar[i][j] = '\0';
			}
			else
			{
				symb_ar[i][j] = symbols[num_average_ar[i][j]];
			}

		}
	}

	for (int i = 0; i < ROWS; i++)
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