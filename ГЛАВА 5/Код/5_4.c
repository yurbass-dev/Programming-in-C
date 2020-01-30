#include <stdio.h>
#define INCH 2.54
#define FOOT 30.48
#define INCH_IN_FOOT 12

int main(void)
{
	float centimeter, inch;
	float foot, foot_2;
	int foot_1;
	
	printf("Введите высоту в сантиметрах\n");
	printf("Для отмены, введите 0.\n");
	scanf("%f", &centimeter);
	
	while (centimeter > 0)
	{
		foot = centimeter / FOOT;
		foot_1 = foot;
		foot_2 = foot - foot_1;
		inch = foot_2 * INCH_IN_FOOT;
		printf("%.1f см = %d футов, %.1f дюймов.\n", centimeter, foot_1, inch);
		printf("Для продолжентя, введите высоту или 0 для отмены.\n");
		scanf("%f", &centimeter);
	}
	
	printf("Программа завершена.\n");

	return 0;
}