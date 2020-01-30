#include <stdio.h>

void Temperatures(double Temp);

int main(void)
{
	double Fahrenheit;

	printf("Введите значение температы по Фаренгейту для вычисления "
		   "эквивалентного значения температуры по Цельсию и по Кельвину: ");

	while (scanf("%lf", &Fahrenheit) == 1)
	{
		Temperatures(Fahrenheit);
	}

	printf("\nКонец программы.\n");

	return 0;
}

void Temperatures(double Temp)
{
	double Celsius, Kelvin; 
	const float TEMP_CELC_1 = 5.0;
	const float TEMP_CELC_2 = 9.0;
	const float TEMP_CELC_3 = 32.0;
	const float TEMP_KELV = 273.16;

	Celsius = TEMP_CELC_1 / TEMP_CELC_2 * (Temp - TEMP_CELC_3);
	Kelvin = Celsius + TEMP_KELV;

	printf("\nТемпература по Фаренгейту %.2f F = %.2f С по Цельсию = %.2f K по Кельвину.\n", 
		    Temp, Celsius, Kelvin);

	printf("\nВведите следующее значение температуры по Фарингейту (символ q для выхода): ");
}