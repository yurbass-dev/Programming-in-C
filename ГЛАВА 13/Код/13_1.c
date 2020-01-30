#include <stdio.h>
#include <stdlib.h>

#define SIZE 81

int main(void)
{
	char file_name[SIZE];
	FILE *fp;
	char ch;
	unsigned long count = 0;

	printf("Введите имя файла, который хотите открыть: ");
	scanf("%s", file_name);

	if ((fp = fopen(file_name, "r")) == NULL)
	{
		printf("Не удается открыть %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	putchar('\n');
	printf("Файл %s содержит %lu символов.\n", file_name, count);

	return 0;
}