#include <stdio.h>
#define HARM_AVRG(X, Y) (2 / ((1 / (X)) + (1 / (Y))))

int main(void)
{
	float a, b;

	printf("Введите два числа для вычисления их гармонического среднего (0 0 для отмены):\n");
	while ((scanf("%f %f", &a, &b) == 2) && a != 0 && b != 0)
	{
		printf("Гармоническое среднее чисел %g и %g = %g.\n", a, b, HARM_AVRG(a, b));
		puts("Введите следующую пару числе (0 0 для выхода)");
	}

	puts("Программа завершена!");

	return 0;
}