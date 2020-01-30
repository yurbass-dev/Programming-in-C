#include <stdio.h>

//эта программа безупречна
int main(void)
{
	int cows, legs;
	printf("Сколько коровьих ног Вы насчитали?\n");
	scanf("%d", &legs);
	cows = legs / 4;
	printf("Отсюда следует, что есть %d коров(а,ы).\n", cows);
	
	return 0;
}
 
