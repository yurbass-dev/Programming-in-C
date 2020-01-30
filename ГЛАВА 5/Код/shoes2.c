#include <stdio.h>
#define ADJUST 7.31
int main(void)
{
	const double SCALE = 0.333;
	double shoe, foot;
	printf("Размер обуви (мужской)     Длина ступни\n");
	shoe = 3.0;

	while (shoe < 18.5)
	{
		foot = SCALE * shoe +ADJUST;
		printf("%11.1f %21.2f дюймов\n", shoe, foot);
		shoe = shoe + 1.0;
	}

	printf("Если обувь подходит, носите ее.\n");
	return 0;
}