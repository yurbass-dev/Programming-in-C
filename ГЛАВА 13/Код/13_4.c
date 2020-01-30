#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int count_argc = 1;
	FILE *fp;
	char ch;

	if (argc < 2)
	{
		printf("Введите хотя бы одно имя файла.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		while (argc > count_argc)
		{
			if ((fp = fopen(argv[count_argc], "r")) == NULL)
			{
				fprintf(stderr, "Не удалось открыть файл %s.\n", argv[count_argc]);
				exit(EXIT_FAILURE);
			}
			else
			{
				printf("Файл %s открыт:\n\n", argv[count_argc]);
				while ((ch = getc(fp)) != EOF)
				{
					putchar(ch);
				}
				putchar('\n');
				putchar('\n');
			}
			if (fclose(fp) != 0)
				fprintf(stderr, "Не удалось закрыть файл %s.\n", argv[count_argc]);
			printf("Файл %s закрыт.\n\n", argv[count_argc]);
			count_argc++;
		}
	}

	return 0;
}