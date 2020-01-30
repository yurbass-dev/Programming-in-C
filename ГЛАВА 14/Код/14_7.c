#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
char * s_gets(char * st, int n);
struct book 
{
	int marker;						
	char title[MAXTITL]; 
	char author[MAXAUTL]; 
	float value;
};

int main(void) 
{
	struct book library[MAXBKS];
	int nums_book[MAXBKS] = {0};
	int count = 0;
	bool check = true;
	int i = 0;
	int index;
	char ch;
	int num_book;
	FILE * pbooks;
	int size = sizeof(struct book);
	
	if ((pbooks = fopen("book.dat", "rb")) != NULL)
	{
		while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
		{
			if (count == 0)
				puts("Текущее содержимое файла book.dat:");
			if (library[count].marker == 1)
			{
				printf("%d) %s авторства %s: $%.2f\n", count + 1, library[count].title, library[count].author,
													   library[count].value);
				nums_book[count] = count + 1;
			}
			count++;
			
		}
		fclose(pbooks);
		if (count != 0)
		{
			printf("Чтобы изменить содержимое книги введите 'c', чтобы удалить книгу введите 'd'\n");
			printf("(для отмены введите 'enter'): ");
			while ((scanf("%c", &ch) == 1) && ch != '\n')
			{
				check = true;
				while (getchar() != '\n')
					continue;
				if (ch != 'c' && ch != 'd')
				{
					printf("Введите 'c' чтобы изменить содержимое, 'd' чтобы удалить книгу ('enter' для выхода): ");
					continue;
				}
				printf("Введите номер книги, которую хотите изменить или удалить: ");
				while (scanf("%d", &num_book) == 1)
				{
					while (getchar() != '\n')
						continue;
					for (i = 0; i < MAXBKS; i++)
					{
						if (nums_book[i] == num_book)
						{
							check = false;
							break;
						}
					}
					if (check)
						printf("Введите номер книги (от 1 до %d): ", MAXBKS);
					else 
						break;
				}
				if (ch == 'c')
				{
					i = 0;
					puts("Введите названия новой книги.");
					puts("Нажмите [enter] в начале строки, чтобы закончить ввод.");
					while (1)
					{
						if (nums_book[i] == num_book)
						{
							while (s_gets(library[i].title, MAXTITL) != NULL && library[i].title[0] != '\0')
							{
								puts("Теперь введите имя автора."); 
								s_gets(library[i].author, MAXAUTL); 
								puts("Teпepь введите цену книги."); 
								scanf("%f", &library[i].value); 
								while (getchar() != '\n')
									continue; 
								break;
							}
							printf("Чтобы изменить содержимое книги введите 'c', чтобы удалить книгу введите 'd'\n");
							printf("(для отмены введите 'enter'): ");
							break;
						}
						i++;
					}
					
				}
				else if (ch == 'd')
				{
					for (i = 0; i < MAXBKS; i++)
					{
						if (nums_book[i] == num_book)
						{
							library[nums_book[i] - 1].marker = 0;
							count--;
							break;
						}
					}
					printf("Чтобы изменить содержимое книги введите 'c', чтобы удалить книгу введите 'd'\n");
					printf("(для отмены введите 'enter'): ");
				}
			}
		}
	}
	if (count == MAXBKS)
	{
		fputs("Фaйл book.dat заполнен.", stderr);
		exit(2); 
	}
	puts("Введите названия новых книг.");
	puts("Нажмите [enter] в начале строки, чтобы закончить ввод.");
	for (i = 0; count < MAXBKS; i++)
	{
		if (library[i].marker == 0)
		{
			while (count < MAXBKS && s_gets(library[i].title, MAXTITL) != NULL && library[i].title[0] != '\0')
			{
				puts("Теперь введите имя автора."); 
				s_gets(library[i].author, MAXAUTL); 
				puts("Teпepь введите цену книги."); 
				scanf("%f", &library[i].value); 
				while (getchar() != '\n')
					continue; 
				library[i].marker = 1;
				count++;
				if (count < MAXBKS)
					puts("Введите название следующей книги.");
				break;
			}
		}
		if (library[i].title[0] == '\0')
			break;
	}

	if (count > 0)
	{
		i = 0;
		puts("Каталог ваших книг:");
		for (index = 0; index <= count; index++)
		{
			if (library[index].marker == 1)
				printf("%d) %s авторства %s: $%.2f\n", index + 1, library[index].title, library[index].author, library[index].value);
		}
	}
	else
		puts("Вообще нет книг? Очень плохо.\n");
	puts("Программа завершена.\n"); 
	if ((pbooks = fopen("book.dat", "wb")) == NULL)
		puts("Не удалось сохранить данные в файл.");
	else
	{
		for (i = 0; i < MAXBKS; i++)
		{
			if (library[i].marker == 1)
				fwrite(&library[i], size, 1, pbooks);
		}
	}
	fclose(pbooks);

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









