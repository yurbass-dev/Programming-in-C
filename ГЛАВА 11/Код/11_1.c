#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10

char * delete_space(char * arr, int n);

int main(void)
{
	char array[SIZE];
	char * check;

	check = delete_space(array, SIZE - 1);
	if (check)
		puts(array);
	else
		puts("Неверный ввод!");

	return 0;
}

char * delete_space(char * arr, int n)
{
	char ch;
	int i;

	for (i = 0; i < n; i++)
	{
		if ((ch = getchar()) == EOF)
		{
			arr = NULL;
			break;
		}
		else
			arr[i] = ch;
	}
	if (ch != EOF)
		arr[i] = '\0';

	return arr;
}