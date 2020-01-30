#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int byte;
	FILE *source;
	FILE *copy;

	if (argc != 3)
	{
		fprintf(stdout, "Используйте %s %s %s\n", argv[0], "source", "target");
		exit(EXIT_FAILURE);
	}

	if ((source = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Ошибка пры открытии %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	else if((copy = fopen(argv[2], "wb")) == NULL)
	{
		fprintf(stderr, "Ошибка пры открытии %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while ((byte = getc(source)) != EOF)
	{
		putc(byte, copy);
	}

	fclose(source);
	fclose(copy);

	puts("Программа завершена!");

	return 0;
}