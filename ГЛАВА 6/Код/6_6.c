#include <stdio.h>
int main(void)
{
	int i;
	int high, low;

	printf("Для создания таблици, введите целое число:\n");
	printf("верхний предел таблицы: ");
	scanf("%d", &high);

	printf("и введите нижний предел таблици: ");
	scanf("%d", &low);

	printf("\nЧисло     Квадрат     Куб\n");

	for(i = low; i <= high; i++)
	{
		printf("%3d %11d %9d", i, i * i, i * i * i);
		printf("\n");
	}

	return 0;
}