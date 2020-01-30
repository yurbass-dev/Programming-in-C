#include <stdio.h>
int main(void)
{
	int over_int = 2147483647;
	unsigned int over_u_int = 4294967295;
	float over_flt = 3.402823e38;
	double over_dbl = 1.797693e308;
	float lost_flt = 0.123456;

	printf("Переполнение в типе int при 2147483647 + 1: %d\n", over_int + 1);
	printf("Переполнение в типе int при 2147483647 + 2: %d\n", over_int + 2);
	printf("Переполнение в типе unsigned int при 4294967295 + 1: %d\n", over_u_int + 1);
	printf("Переполнение в типе unsigned int при 4294967295 + 2: %d\n", over_u_int + 2);
	printf("Переполнение в типе float при 3.402823e38 + 1: %e\n", over_flt + 1);
	printf("Переполнение в типе float при 3.402823e38 * 2: %e\n", over_flt * 2);
	printf("Переполнение в типе double при 1.797693e308 + 1: %e\n", over_dbl + 1);
	printf("Переполнение в типе double при 1.797693e308 * 2: %e\n", over_dbl * 2);
	printf("Потеря значимости в типе float при 0.123456 / 100: %f\n", lost_flt / 100);

	return 0;
}