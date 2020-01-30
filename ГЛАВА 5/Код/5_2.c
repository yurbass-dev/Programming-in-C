#include <stdio.h>
int main(void)
{
	int number, second_num;
	printf("Введите целое число:\n");
	scanf("%d", &number);
	second_num = number + 11;
	
	while ( number < second_num)
		printf("%4d", number++);
	printf("\n");
	
	return 0;
}
