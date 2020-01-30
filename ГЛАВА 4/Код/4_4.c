#include <stdio.h>
int main(void)
{
	float height;
	char name[20];

	printf("Здравствуйте! Как Вас зовут?\n");
	scanf("%s", name);
	printf("Введите Ваш рост в сантиметрах: \n");
	scanf("%f", &height);
	printf("%s, Ваш рост составляет %.2f метров!\n", name, height / 100);

	return 0;
}