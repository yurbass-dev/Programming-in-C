#include <stdio.h>

int main(int argc, char * argv[])
{
	int check = 0;
	if (argc < 2)
	{
		puts("Вы должны ввести хотя бы один аргумент.");
		check = 1;
	}
	else
		for (int i = argc - 1; i > 0; i--)
			puts(argv[i]);

	return check;
}


