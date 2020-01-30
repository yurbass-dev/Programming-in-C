#include <stdio.h>
int main(void)
{
	int i;
	double sum_Dafna = 100.0;
	double sum_Deydra = 100.0;

	for (i = 0; sum_Deydra <= sum_Dafna; i++)
	{
		sum_Dafna += 100.0 * 0.10;
		sum_Deydra += sum_Deydra * 0.05;
	}

	printf("Потребовалось %d лет, чтобы сумма на счету Дейдры превзошла сумму на счету Дафны.\n", i);
	printf("Сумма Дафны $%.2f и сумма Дейдры $%.2f после %d лет.\n", sum_Dafna, sum_Deydra, i);

	return 0;
}