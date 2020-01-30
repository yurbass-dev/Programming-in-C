#include <stdio.h>

void critic(int * pt_units);

int main(void)
{
	int units;

	printf("Сколько фунтов весит маленький бочонок масла?\n");
	scanf("%d", &units);
	while (units != 56)
		critic(&units);
	printf("Вы знали это!\n");

	return 0;
}

void critic(int * pt_units)
{
	printf("Вам не повезло. Попробуйте еще раз.\n");
	scanf("%d", pt_units);
}