#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 81


int main(void)
{
	FILE *in, *out;
	int ch;
	char name_src[LEN];
	char name_dest[LEN];
	int count = 0;

	printf("Введите имя исходного файла:\n");
	scanf("%s", name_src);

	if ((in = fopen(name_src, "r")) == NULL)
	{
		fprintf(stderr, "Не удается открыть файл \"%s\"\n", name_src);
		exit(EXIT_FAILURE);
	}
	
	strncpy(name_dest, name_src, LEN - 5);
	name_dest[LEN - 5] = '\0';
	strcat(name_dest, ".red");

	if ((out = fopen(name_dest, "w")) == NULL)
	{
		fprintf(stderr, "Не удается создать выходной файл.\n");
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(in)) != EOF)
	{
		if (count++ % 3 == 0)
			putc(ch, out);
	}
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Ошибка при закрытии файлов.\n");

	printf("Программа завершена!\n");

	return 0;
}