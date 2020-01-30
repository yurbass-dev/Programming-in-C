#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
#define RANGE 10

int main(void)
{
	int seed;
	int num;
	int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0, ten = 0;

	printf("Введите целое число для генерации 1000 случайных чисел: ");
	scanf("%d", &seed);
	srand(seed);
	for (int i = 0; i < SIZE; i++)
	{
		num = rand() % RANGE + 1;
		if (num == 1)
			one++;
		else if (num == 2)
			two++;
		else if (num == 3)
			three++;
		else if (num == 4)
			four++;
		else if (num == 5)
			five++;
		else if (num == 6)
			six++;
		else if (num == 7)
			seven++;
		else if (num == 8)
			eight++;
		else if (num == 9)
			nine++;
		else if (num == 10)
			ten++;
	}

	printf("Из 1000 случайный чисел получилось:\n");
	printf("1  - %d\n", one);
	printf("2  - %d\n", two);
	printf("3  - %d\n", three);
	printf("4  - %d\n", four);
	printf("5  - %d\n", five);
	printf("6  - %d\n", six);
	printf("7  - %d\n", seven);
	printf("8  - %d\n", eight);
	printf("9  - %d\n", nine);
	printf("10 - %d\n", ten);


	return 0;
}