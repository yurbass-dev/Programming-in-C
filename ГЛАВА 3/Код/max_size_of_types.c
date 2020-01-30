#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(void)
{
	printf("Количество битов в типе char: %d\n", CHAR_BIT);
	printf("Максимально значение типа char: %d\n", CHAR_MAX);
	printf("Минимальное значение типа short: %d\n", SHRT_MIN);
	printf("Максимальное значение типа short: %d\n", SHRT_MAX);
	printf("Минимальное значение типа int: %d\n", INT_MIN);
	printf("Максимальное значение типа int: %d\n", INT_MAX);
	printf("Максимальное значение типа unsigned int: %ld\n", UINT_MAX);
	printf("Минимальное значение типа long: %ld\n", LONG_MIN);
	printf("Максимальное значение типа long: %ld\n", LONG_MAX);
	printf("Максимальное значение типа long long: %lld\n", LLONG_MAX);
	printf("Количество битов в мантиссе типа float: %d\n", FLT_MANT_DIG);
	printf("Минимальное количество значащих десятичных цифр типа float: %d\n", FLT_DIG);
	printf("Максимальное значение для положительного числа типа float: %e\n", FLT_MAX);
	printf("Количество битов в мантиссе типа double: %d\n", DBL_MANT_DIG);
	printf("Минимальное количество значащих десятичных цифр типа double: %d\n", DBL_DIG);
	printf("Максимальное значение для положительного числа типа double: %e\n", DBL_MAX);

	return 0;
}