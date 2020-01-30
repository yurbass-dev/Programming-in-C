#include <stdio.h>
#define SPACE ' '
#define ENTER '\n'

int main(void)
{
	char ch;
	int space_ch = 0;
	int enter_ch = 0;
	int other_ch = 0;

	printf("Введите данные, для подсчета в них символов пробела,"
	       "новой строки и остальных символов.\n");
	printf("Для завершения подсчета символов, введите #.\n");

	while ((ch = getchar()) != '#')
	{
		if (ch == SPACE)
			space_ch++;
		else if (ch == ENTER)
			enter_ch++;
		else
			other_ch++;

	}
	printf("Вы ввели %d пробелов, %d символов новой строки и %d остальных символов.\n", space_ch, enter_ch, other_ch);
	
	return 0;
}