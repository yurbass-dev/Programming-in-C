#include <stdio.h>
#include <stdlib.h>

#define SIZE 256

int main(int argc, char * argv[])
{
	char ch;
	char symbol;
	char str[SIZE];
	FILE *fp;

	if (argc < 3)
	{
		printf("Запускайте программу с двумя аргументами (первый - символ, второй - имя файла).\n");
		printf("Пример: %s a notes\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	symbol = argv[1][0];
	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "Не удается открыть файл %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (!feof(fp))
		{
			if (fgets(str, SIZE, fp))
			{
				for (int i = 0; i < SIZE && str[i] != '\0'; i++)
				{
					if (str[i] == symbol)
					{
						fputs(str, stdout);
						break;
					}
				}
			}
		}
	}
	putchar('\n');
	if (fclose(fp) != 0)
		fprintf(stderr, "Файл не был закрыт.\n");

	return 0;
}