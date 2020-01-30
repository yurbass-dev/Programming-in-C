#include <stdio.h>
#include <ctype.h>

int number_of_character(char);

int main(void)
{
	char ch;

	while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch))
		{
			printf("\nCharacter %c - alpha. ", ch);
			printf("Number of character %c in alpabet is %d.\n", ch, number_of_character(ch));
		}
		else
			printf("Character %c - no alpha!\n", ch);
	}

	return 0;
}

int number_of_character(char ch)
{
	int number;

	if (isalpha(ch))
	{	
		if(isupper(ch))
			number = ch - 64;
		else
			number = ch - 96;

		return number;
	}
	else
		return -1;
}