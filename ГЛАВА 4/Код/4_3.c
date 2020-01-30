#include <stdio.h>
int main(void)
{
	float num;

	printf("Введите число с плавающей точкой: ");
	scanf("%f", &num);
	printf("\nДесятичная представление: %.1f.\n", num);
	printf("Экспоненциальная форма: %.1e.\n", num);
	printf("\nДесятичная представление: %+.3f.\n", num);
	printf("Экспоненциальная форма: %.3E.\n", num);

	return 0;
}