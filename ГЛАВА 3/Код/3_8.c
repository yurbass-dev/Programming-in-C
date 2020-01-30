#include <stdio.h>
int main(void)
{
		float cup;
		float pinta = 2;
		float uncia = 8;
		float stol_lozhka = 16;
		float chai_lozhka = 48;
		printf("Введите количество чашек для перевода в другие емкости: ");

		scanf("%f", &cup);

		printf("\nВ %.1f чашках содержиться %.2f пинт.\n", cup, cup / pinta);
		printf("В %.1f чашках содержиться %.2f унций.\n", cup, cup * uncia);
		printf("В %.1f чашках содержиться %.2f столовых ложек.\n", cup, cup * stol_lozhka);
		printf("В %.1f чашках содержиться %.2f чайных ложек.\n", cup, cup * chai_lozhka);

		return 0;
}