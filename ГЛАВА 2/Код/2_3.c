//Программа преобразовывает мой возраст в годах в количество дней.

#include <stdio.h>

int main(void)
{
	int vozrast, dni;

	vozrast = 24;
	dni = vozrast * 365;

	printf("Мой возраст %d года и это составляет %d дня (дней, день).\n", vozrast, dni);

	return 0;
}