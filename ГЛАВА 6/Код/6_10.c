#include <stdio.h>

int result(int n, int b);

int main(void)
{
	int sqr[100000];
	int i, j, a, b;
	int low, high, sum;

	printf("Введите нижний и верхний целочисленные пределы: ");
	scanf("%d %d", &low, &high);

	for( ; low < high; )
	{	
		for(i = low, j = 0; i <= high; i++, j++)
			sqr[j] = i * i;

		for(a = 0; a <= high - low; a++)
			sum += sqr[a];   

		printf("Cумма квадратов целых чисел от %d до %d равна %d\n", low * low, high * high, sum);
		printf("Введите следующую комбинацию пределов: ");
		scanf("%d %d", &low, &high);
	}

	printf("Работа завершена!\n");

	return 0;
}