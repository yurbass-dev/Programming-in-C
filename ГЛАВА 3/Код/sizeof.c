#include <stdio.h>
 
int main(void)
{
	printf("Тип данных char имеет размер: %zd байт(ов).\n", sizeof(char));
	printf("Тип данных short имеет размер: %zd байт(ов).\n", sizeof(short));
	printf("Тип данных int имеет размер: %zd байт(ов).\n", sizeof(int));
	printf("Тип данных long имеет размер: %zd байт(ов).\n", sizeof(long));
	printf("Тип данных long long имеет размер: %zd байт(ов).\n", sizeof(long long));
	printf("Тип данных float имеет размер: %zd байт(ов).\n", sizeof(float));
	printf("Тип данных double имеет размер: %zd байт(ов).\n", sizeof(double));
	printf("Тип данных long double имеет размер: %zd байт(ов).\n", sizeof(long double));
	
	return 0;
}
 
