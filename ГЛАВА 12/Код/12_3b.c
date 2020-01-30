#include <stdio.h>
#include "12_3a.h"

int main(void)
{
	int mode;
	int prev_mode = 0;
	float distance;
	float fuel_consumption;

	printf("Введите 0 для метрического режима или 1 для американского режима: ");
	scanf("%d", &mode);
	while (mode >= 0)
	{
		mode = set_mode(&mode, &prev_mode);
		get_info(mode, &distance, &fuel_consumption);
		show_info(mode, distance, fuel_consumption);
		printf("Введите 0 для метрического режима или 1 для американского режима\n");
		printf("(-1 для завершения): ");
		scanf("%d", &mode);
	}

	printf("Программа завершена.\n");

	return 0;
}

