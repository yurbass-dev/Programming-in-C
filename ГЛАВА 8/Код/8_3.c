#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int upper = 0;
	int lower = 0;
	int other = 0;
	char ch;

	while ((ch = getchar()) != EOF)
	{
		if (isupper(ch))
			upper++;
		else if (islower(ch))
			lower++;
		else
			other++;
	}
	printf("Количество прописных букв составляет: %d, строчных %d и "
		   "остальных символов %d.\n", upper, lower, other);

	return 0;
}
