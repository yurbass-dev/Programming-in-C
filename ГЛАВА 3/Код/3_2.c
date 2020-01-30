#include <stdio.h>
int main(void)
{
		char kod;
		printf("Введите числовой код для получения символа: \n");
		scanf("%d", &kod);
		printf("Вы ввели число %d, что соответствует символу %c.\n", kod, kod);

		return 0;
}
