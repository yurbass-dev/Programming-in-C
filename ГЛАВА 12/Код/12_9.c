#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	int count_words;
	char temp[40];
	char **pt = NULL;

	printf("Сколько слов вы хотите ввести? ");
	scanf("%d", &count_words);
	pt = (char **) malloc(count_words * sizeof(char *));
	printf("Теперь введите %d слов:\n", count_words);
	
	for (int i = 0; i < count_words; i++)
	{
		scanf("%s", temp);
		pt[i] = (char *) malloc(strlen(temp));
		for (int j = 0; j < strlen(temp); j++)
		{
			pt[i][j] = temp[j];
		}
	}

	printf("Вот введенные вами слова:\n");
	for (int i = 0; i < count_words; i++)
	{
		printf("%s\n", pt[i]);
	}
	free(pt);
	

	return 0;
}