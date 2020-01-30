#include <stdio.h>
#define GALLON_LITR 3.785
#define MILE_KM 1.609

int main(void)
{
	float mile;
	float gallon;
	float km;
	float litr;

	printf("Введите количество преодоленных миль:\n");
	scanf("%f", &mile);
	printf("И введите количество израсходованного бензина в галолнах:\n");
	scanf("%f", &gallon);

	printf("На одном галлоне бензина, Вы проехали %.1f миль.\n", mile / gallon);

	km = mile * MILE_KM;
	litr = gallon * GALLON_LITR;

	printf("В европейской мере измерения, ваш расход топлива в литрах на 100 киллометров,\nсоставляет: %.1f л/км.\n", litr * 100 /km);

	return 0;
}