#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096

void append(FILE *source, FILE *dest);

int main(int argc, char * argv[])
{
	FILE *fa;
	FILE *fs;
	int count_files;
	char ch;

	if (argc < 3)
	{
		printf("Использование: %s файл назначения исходные файлы\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fa = fopen(argv[1], "a+")) == NULL)
	{
		fprintf(stderr, "Не удается открыть файл назначения %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("Не удается создать выходной буфер\n", stderr);
		exit(EXIT_FAILURE);
	}
	for (count_files = 2; count_files < argc; count_files++)
	{
		if (strcmp(argv[1], argv[count_files]) == 0)	
			fputs("Добавить файл в конец самого себя невозможно\n", stderr);
		else if ((fs = fopen(argv[count_files], "r")) == NULL)
			fprintf(stderr, "Не удается открыть %s\n", argv[count_files]);
		else
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("Не удается создать входной буфер\n", stderr);
				continue;
			}
			append(fs, fa);
			if (ferror(fs) != 0)
				fprintf(stderr, "Ошибка при чтении файла %s.\n", argv[count_files]);
			if (ferror(fa) != 0)
				fprintf(stderr, "Ошибка при записи файла %s.\n", argv[1]);
			fclose(fs);
			printf("Содержимое файла %s добавлено.\n", argv[count_files]);
		}
	}
	printf("Добавление завершено. Количество добавленных файлов %d.\n", count_files - 2);
	rewind(fa);
	printf("Содержимое файла %s:\n", argv[1]);
	while ((ch = getc(fa)) != EOF)
		putchar(ch);
	puts("Отображение завершено.");
	fclose(fa);


	return 0;
}

void append(FILE *source, FILE *dest)
{
	size_t bytes;
	static char temp[BUFSIZE];
	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}