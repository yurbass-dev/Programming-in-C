#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int count_letters = 0;
	int count_words = 0;
	float mid_count_letters;
	char prev = 'A';
	char ch;

	while ((ch = getchar()) != EOF)
	{
		
		if (isalpha(prev) && !isalpha(ch) && !ispunct(ch))
			count_words++;
		else if (isalpha(ch))
		{
			count_letters++;
			prev = ch;
		}
	}
	mid_count_letters = (float) count_letters / count_words;

	printf("Среднее количество букв в словах составляет %.1f.\n", mid_count_letters);
	printf("Kоличество букв %d.\n", count_letters);
	printf("Количество слов %d.\n", count_words);

	return 0;
}