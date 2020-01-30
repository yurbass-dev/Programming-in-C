#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20

int main(int argc, char *argv[])
{
	FILE *in, *out;
	int ch;
	char name[LEN];
	int count = 0;

	if (argc < 2)
	{
		fprintf(stderr, "Использование: %s имя_файла\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((in = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Не удается открыть файл \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	strncpy(name, argv[1], LEN - 5);
	name[LEN - 5] = '\0';
	strcat(name, ".red");
	if ((out = fopen(name, "w")) == NULL)
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

	return 0;
}