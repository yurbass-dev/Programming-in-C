#include <stdio.h>
int main(void)
{
		float age, time;
		printf("Хотите узнать, сколько секунд Вы прожили на данный момент?\n");
		printf("Введите Ваш возраст (количество полных лет): ");
		scanf("%f", &age);
		
		time = 3.156e7;
		
		printf("\nВаш возраст в секундах составляет: %.f секунд.\n", age * time);

		return 0;
}