#include <stdio.h>
int main(void)
{
	char name[40];
	char surname[40];

	printf("Здравствуйте! Введите ваше имя и фамилию:\n");
	scanf("%s" "%s", name, surname);
	printf("\nВаша фамилия и имя: %s, %s.\n", surname, name);

	return 0;
}