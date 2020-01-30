#include <stdio.h>

int main(void)
{
	float first_num;
	float second_num;
	float result;
	char ch;
	char switch_ch;

	printf("Выберите желаемую операцию:\n");
	printf("s. сложение        v. вичитание\n");
	printf("u. умножение       d. деление\n");
	printf("z. завершение\n");

	while ((switch_ch = getchar()) != 'z')
	{
		if (switch_ch == 's' || switch_ch == 'v' || switch_ch == 'u' || switch_ch == 'd')
		{
			printf("Введите первое число: ");
			while (scanf("%f", &first_num) != 1)
			{
				while ((ch = getchar()) != '\n')
				{
					putchar(ch);
					continue;
				}
				printf(" не является числом.\n");
				printf("Введите число, такое как 2.5, -1.78Е8 или 3: ");
			}

			printf("Введите второе число: ");
			while (scanf("%f", &second_num) != 1)
			{
				while ((ch = getchar()) != '\n')
				{
					putchar(ch);
					continue;
				}
				printf(" не является числом.\n");
				printf("Введите число, такое как 2.5, -1.78Е8 или 3: ");
			}

			if (switch_ch == 'd' && second_num == 0)
			{
				do
				{
					printf("Введите число, отличное от 0: ");
					while (scanf("%f", &second_num) != 1)
					{
						while ((ch = getchar()) != '\n')
						{
							putchar(ch);
							continue;
						}
						printf(" не является числом.\n");
						printf("Введите число, такое как 2.5, -1.78Е8 или 3: ");
					}

				}
				while (second_num == 0);
			}

			if (switch_ch == 's')
			{
				result = first_num + second_num;
				printf("%g + %g = %g\n", first_num, second_num, result);
			}
			else if (switch_ch == 'v')
			{
				result = first_num - second_num;
				printf("%g - %g = %g\n", first_num, second_num, result);
			}
			else if (switch_ch == 'u')
			{
				result = first_num * second_num;
				printf("%g * %g = %g\n", first_num, second_num, result);
			}
			else if (switch_ch == 'd')
			{
				result = first_num / second_num;
				printf("%g / %g = %g\n", first_num, second_num, result);
			}
		}

		while (getchar() != '\n')
			continue;

		if (switch_ch != 's' || switch_ch != 'v' || switch_ch != 'u' || switch_ch != 'd')
		{
			printf("Выберите желаемую операцию:\n");
			printf("s. сложение          v. вичитание\n");
			printf("u. умножение         d. деоение\n");
			printf("z. завершение\n");
			continue;
		}
	}
	printf("Программа завершена.\n");
	return 0;
}