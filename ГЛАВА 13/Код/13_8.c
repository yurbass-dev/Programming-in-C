#include <stdio.h>
#include <stdlib.h>

void search_and_count_ch(const char * name, char ch);

int main(int argc, char * argv[])
{
	char ch;
	int count_arg;
	char f_name[81];

	if (argc == 1)
	{
		printf("Введите символ.\n");
		return 1;
	}
	ch = argv[1][0];
	if (argc > 2)
	{
		count_arg = argc;
		for (int i = 2; i < count_arg; i++)
		{
			search_and_count_ch(argv[i], ch);
		}
	}
	else
	{
		printf("Введите имя файла:\n");
		while ((scanf("%s", f_name) == 1) && f_name[0] != 'q')
		{
			search_and_count_ch(f_name, ch);
			printf("Введите имя следующего файла или q для выхода.\n");
		}

	}

	puts("Программа завершена!");

	return 0;
}

void search_and_count_ch(const char * name, char ch)
{
	FILE *fp;
	int count = 0;
	char tmp_ch;

	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Не удалось открыть файл %s.\n", name);
	} 
	else
	{
		tmp_ch = getc(fp);
		while (tmp_ch != EOF)
		{
			if (tmp_ch == ch)
			{
				count++;
			}
			tmp_ch = getc(fp);
		}
		fprintf(stdout, "В файле %s символ '%c' встречается %d раз(а).\n", name, ch, count);
		if (fclose(fp) != 0)
			fprintf(stderr, "Не удалось закрыть файл %s.\n", name);
	}

}