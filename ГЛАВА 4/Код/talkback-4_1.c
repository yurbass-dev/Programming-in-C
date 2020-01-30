#include <stdio.h>
#include <string.h>		// для прототипа функции stren()
#define DENSITY 62.4	// удельная масса человека в фунтах на кубический фут

int main()
{
	float weight, volume;
	int size, letters;
	char name[40];		// name представляет соьой массив из 40 символов

	printf("Здравствуйте! Как вас зовут? (введите свое имя на латинице)\n");	// для правильного подсчета букв в имени функцией strlen(), 
	scanf("%s", name);															// нужно вводить только латинские символы.
	printf("%s, сколько вы весите в фунтах?\n", name);
	scanf("%f", &weight);
	size = sizeof name;
	letters = strlen(name);
	volume = weight / DENSITY;
	printf("Хорошо, %s ваш обьем составляет %.2f кубических футов.\n",
		   	name, volume);
	printf("К тому же ваше имя состоит из %d букв,\n", letters);
	printf("мы располагаем %d байтами для его сохранения.\n", size);

	return 0;
}