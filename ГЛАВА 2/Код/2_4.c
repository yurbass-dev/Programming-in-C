#include <stdio.h>

// создаем прототипы функций
// jolly и deny

void jolly(void);  
void deny(void);   

int main(void)
{
	printf("Он веселый молодец!\nОн веселый молодец!\n");
	jolly();
	deny();

	return 0;
} 

// обьявляем функцию jolly

void jolly(void)
{
	printf("Он веселый молодец!\n");

}

// обьявляем функцию deny

void deny(void)
{
	printf("Никто не может это отрицать!\n");

}