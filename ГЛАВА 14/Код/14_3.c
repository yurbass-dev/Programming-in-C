#include <stdio.h>
#include <string.h>
#define MAXTITL 40 
#define MAXAUTL 40 
#define MAXBKS 100

char * s_gets(char * st, int n);

struct book 
{
	char title[MAXTITL]; 	
	char author[MAXAUTL]; 
	float value;
};

void sort_title(struct book * pt_libr[], int n);
void sort_value(struct book * pt_libr[], int n);


int main (void) 
{
	struct book library[MAXBKS]; 
	int count = 0;
	int index;

	printf("Введите название книги.\n");
	printf ("Нажмите [enter] в начале строки, чтобы закончить ввод.\n"); 
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
		   && library[count].title[0] != '\0') 
	{
		printf("Теперь введите ФИО автора.\n"); 
		s_gets(library[count].author, MAXAUTL); 
		printf ("Теперь введите цену.\n"); 
		scanf("%f", &library[count++].value); 
		while (getchar() != '\n')
			continue; 
		if (count < MAXBKS)
			printf("Введите название следующей книги.\n");
	}
	
	if (count > 0) 
	{
		struct book * pt_libr[count];
		for (int i = 0; i < count; i++)
		{
			pt_libr[i] = &library[i];
		}
		printf("Каталог ваших книг:\n");
		printf("В порядке ввода:\n");
		for (index = 0; index < count; index++)
			printf("%s авторства %s: $%.2f\n", library[index].title, library[index].author, 
			   		library[index].value);
		sort_title(pt_libr, count);
		printf("В алфавитном порядке:\n");
		for (index = 0; index < count; index++)
			printf("%s авторства %s: $%.2f\n", pt_libr[index]->title, pt_libr[index]->author, 
			   		pt_libr[index]->value);
		sort_value(pt_libr, count);
		printf("В порядке возростания цены:\n");
		for (index = 0; index < count; index++)
			printf("%s авторства %s: $%.2f\n", pt_libr[index]->title, pt_libr[index]->author, 
			   		pt_libr[index]->value);
	}
	else
		printf("Вообще нет книг? Очень плохо.\n");

	return 0;
}

char * s_gets(char * st, int n) 
{
	char * ret_val; 
	char * find;
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

void sort_value(struct book * pt_libr[], int n)
{
	struct book * temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i; j < n - 1; j++)
		{
			if (pt_libr[j]->value > pt_libr[j + 1]->value)
			{
				temp = pt_libr[j];
				pt_libr[j] = pt_libr[j + 1];
				pt_libr[j + 1] = temp;
			}
		}
	}
}

void sort_title(struct book * pt_libr[], int n)
{
	struct book * temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i; j < n - 1; j++)
		{
			if (strcmp(pt_libr[j]->title, pt_libr[j + 1]->title) > 0)
			{
				temp = pt_libr[j];
				pt_libr[j] = pt_libr[j + 1];
				pt_libr[j + 1] = temp;
			}
		}
	}
}


