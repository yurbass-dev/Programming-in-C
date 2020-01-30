#include <stdio.h>
#include <string.h>
int main(void)
{
	char name[20];

	printf("Введите ваше имя: ");
	scanf("%s", name);
	printf("\n\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	printf("*%-*s*\n", strlen(name) + 3, name);

	return 0;

}