#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char ch_1;
	char ch_2;
	int count = 0;
	char *first = NULL;
	char *second = NULL;
	FILE *fp_one;
	FILE *fp_two;
	char *name = (char *) malloc(81);       	//выделяем временно память под имя файла 

	printf("Введите имя первого файла:\n");
	scanf("%s", name);
	first = (char *) malloc(strlen(name) + 1);	//выделяем память под массив, в котором будет хранится имя первого файла
	//копируем имя из временого массива
	strcpy(first, name);						
	printf("Введите имя второго файла:\n");
	scanf("%s", name);
	second = (char *) malloc(strlen(name) + 1);	//выделяем память для имени второго файла
	strcpy(second, name);

	free(name);									//очищаем из памяти наш временный массив
	
	if ((fp_one = fopen(first, "r")) == NULL)
	{
		fprintf(stderr, "Не удалось открыть первый файл %s.\n", first);
		exit(EXIT_FAILURE);
	}	
	if ((fp_two = fopen(second, "r")) == NULL)
	{
		fprintf(stderr, "Не удалось открыть второй файл %s.\n", second);
		exit(EXIT_FAILURE);
	}

	ch_1 = getc(fp_one);
	ch_2 = getc(fp_two);

	while (ch_1 != EOF || ch_2 != EOF) 
	{
		while (ch_1 != EOF && ch_1 != '.')  // цикл вывод символы, пока символ не будет точкой или не встретится EOF
		{
			putchar(ch_1);
			ch_1 = getc(fp_one); 
		}
		if (ch_1 != EOF) 
		{
			getc(fp_one);					// удаляем пробел после точки (конец предложения), 
			putchar('.');					// чтобы предложение начиналось в новой строке без символа пробела.
			ch_1 = getc(fp_one); 
			if (ch_2 == EOF)				// выводим строки с одным номером в одной экранной строке
				putchar('\n');
		}
		while (ch_2 != EOF && ch_2 != '.') 
		{
			if (count == 0)					// добавляем пробел после первого предложения
				putchar(' ');
			count = 1;
			putchar(ch_2);
			ch_2 = getc(fp_two); 
		}
		if (ch_2 != EOF) 
		{
			if (ch_1 == EOF)				// удаляем пробел после точки (конец предложения),
				getc(fp_two);				// если первый файл подошел к концу
			putchar('.');
			putchar('\n');
			ch_2 = getc(fp_two); 
		}
	}
	if (fclose(fp_one) != 0)
		fprintf(stderr, "Не удается закрыть файл %s\n", first);
	if (fclose(fp_two) != 0)
		fprintf(stderr, "Не удается закрыть файл %s\n", second);

	putchar('\n');
	puts("Программа завершена!");

	return 0;
}
