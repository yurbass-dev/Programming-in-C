#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZESTR 255

char * s_gets(char * st, int n);

struct stack
{
	char ch;
	struct stack * prev;
};


int main(void)
{
	struct stack * top = NULL;
	struct stack * prev = NULL;
	struct stack * current = NULL;
	char string[SIZESTR];
	int i;

	puts("Введите строку:");
	while (s_gets(string, SIZESTR) != NULL && string[0] != '\0')
	{
		i = 0;
		while (string[i] != '\0')
		{
			top = (struct stack *) malloc(sizeof(struct stack));
			if (top == NULL)
			{
				fprintf(stderr, "Не удалось выделить память.\n");
				exit(EXIT_FAILURE);
			}
			if (i == 0)
			{
				top->prev = NULL;
				top->ch = string[i];
				prev = top;
			}
			else
			{
				top->ch = string[i];
				top->prev = prev;
				prev = top;
			}
			i++;
		}
		current = top;
		while (current != NULL)
		{
			printf("%c", current->ch);
			current = current->prev;
		}
		top = NULL;
		puts("\nВведите строку (enter для выхода):");
	}
	if (top != NULL)
	{
		current = top;
		while (top->prev != NULL)
		{
			free(top);
			top = current->prev;
		}
	}

	puts("Программа завершена!");

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