#include <stdio.h>
int main(void)
{
		float molecula_vodu = 3.0e-23;
		float kolichestvo_kvart, result;
		int kvarta_vodu = 950;

		printf("Масса одной молекулы воды составляет 3.0е-23 грамм, в одной кварте содержиться 950 грамм воды.\n");
		printf("Введите количество кварт воды, для того, чтобы узнать, сколько в них содержиться молекул воды: ");

		scanf("%f", &kolichestvo_kvart);
		
		result = kolichestvo_kvart * kvarta_vodu / molecula_vodu;

		printf("\nВ %.1f квартах воды, содержиться %.5e молекул!\n", kolichestvo_kvart, result);

		return 0;
}