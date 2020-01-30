#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 30

struct softbol
{
	int number;
	char first_name[LEN];
	char last_name[LEN];
	int took_the_ball;
	int hitting_the_ball;
	int passage;
	int jogging;
	float average;
};

int main(void)
{
	FILE * ptFile;
	struct softbol * p_st = NULL;		//указатель на структуру типа softbol
	int count_str = 0;					//количество всех строк
	int count_str2 = 0;					//количество строк без повторений
	int i = 0;					
	char ch;
	int num;
	int indx;
	int took_the_ball = 0;
	int hitting_the_ball = 0;
	int passage = 0;
	int jogging = 0;
	float average = 0.0;


	if ((ptFile = fopen("softbol", "r")) == NULL)
	{
		fprintf(stderr, "Не получилось открыть файл %s.\n", "softbol");
		exit(EXIT_FAILURE);
	} 

	//Считаем сколько строк есть в файле
	char prev = '\n';
	while ((ch = fgetc(ptFile)) && ch != EOF)			
	{
		if (isalnum(ch) && prev == '\n')
			count_str++;
		prev = ch;
	}
	//Если в файле нету данных, завершить программу
	if (count_str == 0)
	{
		fprintf(stderr, "Файл пуст.\n");
		exit(EXIT_FAILURE);
	}
	//Устанавливаем внутренний указатель положения файла в начало файла
	rewind(ptFile);
	//массив для номеров игроков
	int arr[count_str];				
	//Заносим только номера игроков в массив
	while (!feof(ptFile))
	{
		if (i == 0)
		{
			fscanf(ptFile, "%d", &arr[i]);
			i++;
		}
		if (ch == '\n')
		{
			fscanf(ptFile, "%d", &arr[i]);
			i++;
		}
		ch = fgetc(ptFile);
	}

	count_str2 = count_str;
	//находим сколько действительно игроков есть в файле (без повторений)
	for (i = 0; i < count_str; i++)
	{
		for (int j = i + 1; j < count_str; j++)
		{
			if (arr[i] == arr[j])
				count_str2--;
		}
	}
	
	//Выделяем блок памяти под структуры типа softbol и инициализируем все биты нулями
	p_st = (struct softbol *) calloc(count_str2, sizeof(struct softbol));
	if (p_st == NULL)
		exit(EXIT_FAILURE);

	rewind(ptFile);
	//Заносим данные игроков в структуры
	for (i = 0; i < count_str; i++)
	{
		fscanf(ptFile, "%d", &num);
		indx = num - 1;
		if (p_st[indx].number == 0)
		{
			p_st[indx].number = num;
			fscanf(ptFile, "%s %s %d %d %d %d", p_st[indx].first_name, p_st[indx].last_name, &p_st[indx].took_the_ball,
			  	   &p_st[indx].hitting_the_ball, &p_st[indx].passage, &p_st[indx].jogging);
		}
		//Если игрок уже занесен в структуру, то добавляем его поточные результаты к ранне записанным
		else
		{	int one = 0;
			int two = 0;
			int three = 0;
			int four = 0;
			fscanf(ptFile, "%s %s %d %d %d %d", p_st[indx].first_name, p_st[indx].last_name, &one, &two, &three, &four);
			p_st[indx].took_the_ball += one;
			p_st[indx].hitting_the_ball += two;
			p_st[indx].passage += three;
			p_st[indx].jogging += four;
		}
	}
	//Считаем средний уровень достижений по каждому игроку
	for (indx = 0; indx < count_str2; indx++)
	{
		p_st[indx].average = (float) p_st[indx].took_the_ball / (float) p_st[indx].hitting_the_ball;
	}
	//Выводим отсортированный список игроков с их результатами
	for (indx = 0; indx < count_str2; indx++)
	{
		printf("%d %s %s %d %d %d %d %.1f\n", p_st[indx].number, p_st[indx].first_name, p_st[indx].last_name, 
			   p_st[indx].took_the_ball, p_st[indx].hitting_the_ball, p_st[indx].passage, p_st[indx].jogging,
			   p_st[indx].average);
	}

	for (indx = 0; indx < count_str2; indx++)
	{
		took_the_ball += p_st[indx].took_the_ball;
		hitting_the_ball += p_st[indx].hitting_the_ball;
		passage += p_st[indx].passage;
		jogging += p_st[indx].jogging;
		average += p_st[indx].average;
	}
	printf("Суммарные статистические данные по всей команде:\n");
	printf("количество принятий мяча: %d\n", took_the_ball);
	printf("количество нанесенных ударов: %d\n", hitting_the_ball);
	printf("количество проходов: %d\n", passage);
	printf("количество засчитанных пробежек: %d\n", jogging);
	printf("сумма среднего уровня достижений: %.1f\n", average);

	
	if (fclose(ptFile) != 0)
	{
		fprintf(stderr, "Не удалось закрыть файл %s.\n", "softbol");
		exit(EXIT_FAILURE);
	}
	free(p_st);

	return 0;
}