#include <stdio.h>
#include <ctype.h>
#include <stdbool.h> 

int main(void)
{
	char c;
	int low_ct = 0; 
	int up_ct = 0; 
	int dig_ct = 0; 
	int n_words = 0;
	int punc_ct = 0; 
	bool inword = false;

	printf("Введите текст, подлежащий анализу (EOF для завершения):\n"); 
	while ((c = getchar()) != EOF)
	{
		if (islower(c))
			low_ct++;
		else if (isupper(c))
			up_ct++;
		else if (isdigit(c))
			dig_ct++;
		else if (ispunct(c))
			punc_ct++;
		if (!isspace(c) && !inword) 
		{
			inword = true; // начало нового слова
			n_words++; // подсчет слов 
		}
		if (isspace(c) && inword)
			inword = false; // достигнут конец слова
	}
	printf("\nслов = %d, строчных = %d, прописных = %d, "
		   "цифр = %d, препинаний = %d\n",
			n_words,low_ct,up_ct, dig_ct, punc_ct); 

	return 0;
}