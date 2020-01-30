#include <stdio.h>
int main(void)
{
	int num[8];
	int i;

	printf("Введите восемь целых чисел через пробел: ");

	
	for(i = 0; i < 8; i++)
		scanf("%d", &num[i]);

	for(i = 7; i >= 0; i--)
		printf("%d ", num[i]);

	return 0;
}