#include <stdio.h>
#include <string.h>
int main(void)
{
	char word[20];
	int i, size_word;

	printf("Введите слово на английском языке: ");
	scanf("%s", word);

	size_word = strlen(word);

	for(i = size_word; i >= 0; i--)
		printf("%c", word[i]);

	printf("\n");
	
	return 0;
}