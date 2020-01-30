#include <stdio.h>
int main(void)
{
		float rost;
		printf("Хотите узнать, какой у Вас рост в дюймах?\n");
		printf("Введите Ваш рост в сантиметрах: ");

		scanf("%f", &rost);

		printf("\nУдивительно! Ваш рост составляет %.2f дюйма(ов).\n", rost * 2.54);

		return 0;
}