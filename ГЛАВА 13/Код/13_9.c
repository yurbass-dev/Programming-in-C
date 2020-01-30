#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	FILE *fp;
	char word[41];
	int count = 1;

	if ((fp = fopen("wordy", "a+")) == NULL)
	{
		fprintf(stderr, "Не удается открыть файл \"wordy\".\n");
		exit(EXIT_FAILURE);
	}
	rewind(fp);
	while (fgets(word, 41, fp) != NULL)
		count++;
	puts("Введите слова для добавления в файл; для завершения");
	puts("введите символ # в начале строки.");
	while ((scanf("%40s", word) == 1) && (word[0] != '#'))
	{
		fprintf(fp, "%d %s\n", count++, word);
	}
	rewind(fp);
	while (fgets(word, 41, fp) != NULL)
		fputs(word, stdout);
	if (fclose(fp) != 0)
		fprintf(stderr, "Не удалось закрыть файл \"wordy\"\n");
	puts("Программа завершена!");

	return 0;
}