#include <stdio.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

char * s_gets(char *st, int n);

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index;

	printf("Введите название книги.\n");
	printf("Нажмите (enter) в начале строки, чтобы закончить ввод.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
		   && library[count].title[0] != '\0')
	{
		printf("Теперь введите ФИО автора.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Теперь введите цену.\n");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			printf("Введите название следующей книги.\n");
	}
	if (count > 0)
	{
		printf("Каталог ваших книг:\n");
		for (index = 0; index < count; index++)
		{
			printf("%s авторства %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
		}
	}
	else
		printf("Вообще нет книг? Очень плохо.\n");

	return 0;
}

char * s_gets(char *st, int n)
{
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}