#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char * itobs(int n, char * ps);

int main(int argc, char * argv[])
{
	int i, j;
	char result_num[33];
	unsigned int num1;
	unsigned int num2;

	if (argc < 3)
	{
		puts("Нужно ввести 2 числа в доичной системе.");
		exit(EXIT_FAILURE);
	}
	else if (argc >= 3)
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				if (argv[i][j] != '0' && argv[i][j] != '1')
				{
					puts("Нужно вводить число состоящее только из 0 и 1.");
					exit(EXIT_FAILURE);
				}
				j++;
			}
			i++;
		}
	}

	num1 = strtol(argv[1], NULL, 2);
	num2 = strtol(argv[2], NULL, 2);
	itobs(~num1, result_num);
	printf("Первое число с применением операции ~%s = %s.\n", argv[1], result_num);
	itobs(~num2, result_num);
	printf("Второе число с применением операции ~%s = %s.\n", argv[2], result_num);
	itobs(num1 & num2, result_num);
	printf("Результат операции %s & %s = %s.\n", argv[1], argv[2], result_num);
	itobs(num1 | num2, result_num);
	printf("Результат операции %s | %s = %s.\n", argv[1], argv[2], result_num);
	itobs(num1 ^ num2, result_num);
	printf("Результат операции %s ^ %s = %s.\n", argv[1], argv[2], result_num);

	puts("Программа завершена!");

	return 0;
}

char * itobs(int n, char * ps) 
{
	int i;
	const static int size = CHAR_BIT * sizeof(int);

	for (i = size - 1; i >= 0; i--, n >>= 1) 
		ps [i] = (01 & n) + '0';
	ps[size] = '\0';

	return ps; 
}
