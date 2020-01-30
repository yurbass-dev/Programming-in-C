#include <stdio.h>
#include <string.h>
int main(void)
{
	char name[20];
	char surname[20];

	short size_name;
	short size_surname;

	printf("Введите ваше имя и фамилию на русском языке:\n");
	scanf("%s" "%s", name, surname);

	size_name = strlen(name) / 2;
	size_surname = strlen(surname) / 2;

	printf("%s %s\n", name, surname);
	printf("%*d %*d\n", size_name, size_name, size_surname, size_surname);
	printf("%s %s\n", name, surname);
	printf("%-*d %-*d", size_name, size_name, size_surname, size_surname);

	return 0;
}