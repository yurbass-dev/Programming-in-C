#include <stdio.h>
#define SQUARES 64
#define CROP 2E16
 
int main(void)
{
	double current, total;
	int count = 1;
	printf("Квадрат   Текущее количество   Общее количество   Процет от всех\n");
	printf("                зерен               зерен              зерен\n");
	current = total = 1.0;
	printf("%4d %18.2e %19.2e %18.2e\n", count, current, total, total / CROP);
	while (count < SQUARES)
	{
		count = count + 1;
		current = current * 2.0;
		total = total + current;
		printf("%4d %18.2e %19.2e %18.2e\n", count, current, total, total / CROP);
	}
		
	return 0;
}
 
