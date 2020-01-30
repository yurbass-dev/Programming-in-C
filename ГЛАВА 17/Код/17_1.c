#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>
#define TSIZE 45

struct film 
{
	char title[TSIZE]; 
	int rating;
	struct film * next;
	struct film * prev;
};
char * s_gets(char * st, int n);

int main(void) 
{
	struct film * head = NULL; 
	struct film * last = NULL;
	struct film * prev, * current; 
	char input[TSIZE];
	int ch;

	puts("Введите название первого фильма:");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film *) malloc(sizeof(struct film)); 
		if (current == NULL)
		{
			fprintf(stderr, "Не удалось выделить память.\n");
			exit(EXIT_FAILURE);
		}
		if (head == NULL)
		{
			head = current;				// если это первая структура, устанавливай указатель на начало списка
			head->prev = NULL;			// и устанавливаем нулевой указатель, чтобы это был конец списка,
		}								// если двигаться с конца в начало (в обратном направлении)
		else
		{ 				
			prev->next = current;		// если это не первая структура, то устанавливаем указатель предыдущей 
			current->prev = prev;		// структуры на поточную и указатель поточной на предыдущую структуру
		}
		current->next = NULL;			// устанавливаем в указатель на следующую структуру нулевой указатель 
		strcpy(current->title, input);
		puts("Введите свое значение рейтинга <0-10>:"); 
		scanf("%d", &current->rating);
		while (getchar() != '\n') 
			continue;
		puts("Введите название следующего фильма (иди пустую строку для прекращения ввода):"); 
		prev = current;					// присваиваем поточную структуру предыдущей
		last = current;					// присваиваем поточную структуру указателю на конец списка
	}

	printf("Введите l для просмотра списка в исходном порядке или r для просмотра\n");
	printf("в обратном порядке (q для выхода): ");
	while ((ch = getchar()) && ch != 'q')
	{ 
		while (getchar() != '\n') 
			continue;
		ch = tolower(ch);
		if (ch != 'l' && ch != 'r' && ch != 'q')
		{
			printf("Введите букву 'l' или 'r' (для выхода 'q'): ");
			continue;
		}
		if (ch == 'l')
		{
			if (head == NULL)
				printf("Данные не введены."); 
			else
				printf("Список фильмов:\n"); 

			current = head;						// устанавливаем поточный указатель на начало списка

			while (current != NULL) 
			{
				printf("Фильм: %s Рейтинг: %d\n", current->title, current->rating);
				current = current->next; 
			}
		}
		else if (ch == 'r')
		{
			if (last == NULL)
				printf("Данные не введены.");
			else
				printf("Обратный список фильмов:\n");

			current = last;						// устанавливаем поточный указатель на конец списка
												// чтобы двигаться в обратном направлении
			while (current != NULL)
			{
				printf("Фильм: %s Рейтинг: %d\n", current->title, current->rating);
				current = current->prev; 
			}
		}
		printf("Введите l для просмотра списка в исходном порядке или r для просмотра\n");
		printf("в обратном порядке (q для выхода): ");
	}
	
	while (head != NULL)
	{
		current = head;
		head = current->next; 
		free(current);
	}

	printf("Программа завершена.\n");

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
			*find = '\0' ; 
		else
			while (getchar() != '\n') 
				continue;
	}
	return ret_val;
}