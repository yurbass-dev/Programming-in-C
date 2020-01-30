#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch, prev;
	int ct_words = 0;
	int ct_lowercase_letter = 0;
	int ct_uppercase_letter = 0;
	int ct_punct_ch = 0;
	int ct_digit = 0;

	while((ch = getchar()) != EOF)
	{	
		if ((isspace(ch) || isdigit(ch) || ispunct(ch)) && isalpha(prev))
			ct_words++;
		if (islower(ch))
			ct_lowercase_letter++;
		else if(isupper(ch))
			ct_uppercase_letter++;
		else if(ispunct(ch))
			ct_punct_ch++;
		else if(isdigit(ch))
			ct_digit++;
		
		prev = ch;
	}
	printf("Количество слов: %d\n", ct_words);
	printf("Количество прописных букв: %d\n", ct_lowercase_letter);
	printf("Количество строчных букв: %d\n", ct_uppercase_letter);
	printf("Количество знаков препинания: %d\n", ct_punct_ch);
	printf("Количество цифр: %d\n", ct_digit);

	return 0;
}