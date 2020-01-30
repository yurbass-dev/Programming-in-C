#include <stdio.h>
#include "12_3a.h"

int set_mode(int * mode, int * prev_mode)
{
	if (*mode != 0 && *mode != 1)
	{
		if (*prev_mode == 0)
		{
			printf("Указан недопустимый режим. Используется режим 0 (метрический).\n");
			*prev_mode = 0;
		}
		else if (*prev_mode == 1)
		{
			printf("Указан недопустимый режим. Используется режим 1 (американский).\n");
			*prev_mode = 1;
		}
		return *prev_mode;
	}
	else
	{
		*prev_mode = *mode;
		return *mode;
	}

}

void get_info(int mode, float * distance, float * fuel_consumption)
{
	if (mode == 0)
	{
		printf("Введите пройденное расстояние в километрах: ");
		scanf("%f", distance);
		printf("Введите обьем израсходованного топлива в литрах: ");
		scanf("%f", fuel_consumption);
	}
	else if (mode == 1)
	{
		printf("Введите пройденное расстояние в милях: ");
		scanf("%f", distance);
		printf("Введите обьем израсходованного топлива в галлонах: ");
		scanf("%f", fuel_consumption);
	}
}

void show_info(int mode, float distance, float fuel_consumption)
{
	if (mode == 0)
	{
		printf("Расход топлива составляет %.2f литров на 100 км.\n", (fuel_consumption * 100) / distance);
	}
	else if (mode == 1)
	{
		printf("Расход топлива составляет %.2f мили на галлон.\n", distance / fuel_consumption);
	}
}