#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[])
{
	double num;
	int pov;
	int check = 0;

	if (argc < 3)
	{
		puts("Введите число с плавающей точкой и целочисленую степень.");
		check = 1;
	}
	else
	{
		num = atof(argv[1]);
		pov = atoi(argv[2]);
		printf("%.2f в %d степени = %.2f\n", num, pov, pow(num, pov));
	}

	return check;
}