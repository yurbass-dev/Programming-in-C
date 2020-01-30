#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char * argv[])
{
	char ch;
	char flag;

	if (argc == 1)
		flag = 'p';
	else
	{	
		if (!strcmp(argv[1], "-p"))
			flag = 'p';
		else if (!strcmp(argv[1], "-u"))
			flag = 'u';
		else if (!strcmp(argv[1], "-l"))
			flag = 'l';
	}
	
	while ((ch = getchar()) != EOF)
	{
		if (flag == 'p')
			putchar(ch);
		else if (flag == 'u')
			putchar(toupper(ch));
		else if (flag == 'l')
			putchar(tolower(ch));
	}
	puts("Программа завершена.");

	return 0;
}