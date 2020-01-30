#include <stdio.h>
int main(void)
{
		float number;
		printf("Введите число с плавающей точкой: ");
		scanf("%f", &number);
		printf("\nЗапись с фиксированной точкой: %f.\n", number);
		printf("Экспоненциальная форма записи: %e.\n", number);
		printf("Двоично-экспоненциальное представление: %a.\n", number);

		return 0;
}