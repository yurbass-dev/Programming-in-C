#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 301

int main(int argc, char *argv[])
{
	FILE *fp;
	char str[SIZE];
	char *pt_str = NULL;
	int check = 0;

	if (argc != 3)
	{
		printf("Введите строку и имя файла.\n");
		printf("Пример: ./13_11 \"Hello, world\" file.txt\n");
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "Не удалось открыть файл %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while (!feof(fp))
	{
		fgets(str, SIZE, fp);
		pt_str = strstr(str, argv[1]);
		if (pt_str)
		{
			fputs(pt_str, stdout);
			check = 1;
		}
		
	}
	if (check == 0)
	{
		printf("Строки %s\n", argv[1]);
		printf("в файле %s не обнаружено.\n", argv[2]);
	}

	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Не удалось закрыть файл %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	puts("Программа завершена!");

	return 0;
}