#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	long position, last;
	char name[81];
	char ch;

	printf("Введите имя файла, который хотите открыть:\n");
	scanf("%s", name);

	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Не удается открыть файл %s.\n", name);
		exit(EXIT_FAILURE);
	}
	printf("Введите число для нахождения позиции в файле: ");
	fseek(fp, 0L, SEEK_END);
	last = ftell(fp);
	while ((scanf("%ld", &position) == 1) && position >= 0)
	{
		if (position > last)
		{
			printf("Вы ввели позицию, которой нету в файле.\n");
			printf("Введите меньшее число.");
		}
		else
		{
			for (; position < last; position++)
			{
				fseek(fp, position, SEEK_SET);
				ch = getc(fp);
				if (ch != EOF && ch != '\n')
					putchar(ch);
			}
		}
		printf("\nВведите следующую позицию (q или отрицательно число для выхода).\n");
	}

	if (fclose(fp) != 0)
		fprintf(stderr, "Не удалось закрыть файл %s.\n", name);

	puts("Программа завершена!");

	return 0;
}