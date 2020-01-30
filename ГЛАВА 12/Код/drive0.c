#include <stdio.h>
#include <time.h>

extern void srand1(unsigned int seed);
extern int rand1(void);

int main(void)
{
	int count;
	unsigned seed;

	printf("%u\n", (unsigned int) time(0));

	printf("Введите желаемое начальное число.\n");
	while (scanf("%u", &seed) == 1)
	{
		srand1((unsigned int) time(0));

		for (count = 0; count < 5; count++)
			printf("%d\n", rand1());
		printf("Введите следующее начальное число (q для завершения):\n");	
	}
	printf("Программа завершена.\n");

	return 0;
}