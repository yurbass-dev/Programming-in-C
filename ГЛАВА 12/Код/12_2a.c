#include <stdio.h>
#include "12_2a.h"

static int mode = 0;
static float distance;
static float fuel_consumption;

void set_mode(int mode_1)
{
	if (mode_1 != 0 && mode_1 != 1)
	{
		if (mode == 0)
		{
			printf("Указан недопустимый режим. Используется режим 0 (метрический).\n");
			mode = 0;
		}
		else if (mode == 1)
		{
			printf("Указан недопустимый режим. Используется режим 1 (американский).\n");
			mode = 1;
		}
	}
	else
		mode = mode_1;
}

void get_info(void)
{
	if (mode == 0)
	{
		printf("Введите пройденное расстояние в километрах: ");
		scanf("%f", &distance);
		printf("Введите обьем израсходованного топлива в литрах: ");
		scanf("%f", &fuel_consumption);
	}
	else if (mode == 1)
	{
		printf("Введите пройденное расстояние в милях: ");
		scanf("%f", &distance);
		printf("Введите обьем израсходованного топлива в галлонах: ");
		scanf("%f", &fuel_consumption);
	}
}

void show_info(void)
{
	if (mode == 0)
	{
		printf("Расход топлива составляет %g литров на 100 км.\n", (fuel_consumption * 100) / distance);
	}
	else if (mode == 1)
	{
		printf("Расход топлива составляет %g мили на галлон.\n", distance / fuel_consumption);
	}
}