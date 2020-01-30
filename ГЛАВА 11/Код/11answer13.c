
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ANSWER "Grant"
#define SIZE 40

char * s_gets (char * st, int n);
void toUpper(char * string);

int main (void)
{
	char try[SIZE];
	char answer[] = ANSWER;

	toUpper(answer);
	puts("Кто похоронен в могиле Гранта?"); 
	s_gets(try, SIZE);
	toUpper(try);
	while (strcmp(try, answer) != 0)
	{
		puts("Неправильно! Попытайтесь еще раз.");
		s_gets(try, SIZE); 
		toUpper(try);
	}
		puts("Tenepь правильно!");

	return 0; 
}

void toUpper(char * string)
{
	for (int i = 0; i < strlen(string); i++)
		string[i] = toupper(string[i]);
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin); 
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0') 
			i++;
		if (st[i] == '\n') 
			st[i] = '\0';
		else 
			while (getchar() != '\n')
				continue; 
	}
	return ret_val;
}