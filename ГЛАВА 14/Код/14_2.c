#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 10

int count_days(int day, const char * month, int year);

struct month 
{
	char name[10];
	char abbr[4];
	int days;
	int number;
};

struct month common_year[12] = 
{
	{"January", "Jan", 31, 1},
	{"February", "Feb", 28, 2},
	{"March", "Mar", 31, 3},
	{"April", "Apr", 30, 4},
	{"May", "May", 31, 5},
	{"June", "Jun", 30, 6},
	{"July", "Jul", 31, 7},
	{"August", "Aug", 31, 8},
	{"September", "Sep", 30, 9},
	{"October", "Oct", 31, 10},
	{"November", "Nov", 30, 11},
	{"December", "Dec", 31, 12}
};

struct month leap_year[12] = 
{
	{"January", "Jan", 31, 1},
	{"February", "Feb", 29, 2},
	{"March", "Mar", 31, 3},
	{"April", "Apr", 30, 4},
	{"May", "May", 31, 5},
	{"June", "Jun", 30, 6},
	{"July", "Jul", 31, 7},
	{"August", "Aug", 31, 8},
	{"September", "Sep", 30, 9},
	{"October", "Oct", 31, 10},
	{"November", "Nov", 30, 11},
	{"December", "Dec", 31, 12}
};

int main(void)
{
	int day;
	int year;
	char month[SIZE];
	int days;
	
	printf("Введите день:");
	while (scanf("%d", &day) == 1)
	{
		printf("Введите месяц:");
		scanf("%s", month);
		printf("Введите год:");
		scanf("%d", &year);

		if ((days = count_days(day, month, year)))
		{
			printf("Количество дней с начала %d года по:\n", year);
			printf("%d %s составляет %d день(дня, дней).\n", day, month, days);
		}
		else
			printf("Введите название месяца верно.\n");
		printf("Введите день (q для выхода):");
	}


	return 0;
}

int count_days(int day, const char * month, int year)
{
	int days = 0;
	int check = 0;
	char * ptmonth = (char *) malloc(strlen(month) + 1);
 	struct month * pt_year;
 	
 	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))		//проверка на высокосный год
		pt_year = leap_year;											//и присвоение указателю адреса 
	else																//соответсвующей структуры
		pt_year = common_year;

 	if (isalpha(month[0]))
 	{
		ptmonth[0] = toupper(month[0]);									//если название месяца это полное слово или 
		for (int i = 1; month[i] != '\0'; i++)							//аббревиатура, то 1-ю букву делаем большой
		{																//остальные маленькими
			ptmonth[i] = tolower(month[i]);
		}
		ptmonth[strlen(month) + 1] = '\0';								//добавляем символ конца строки
	}
	else if (isdigit(month[0]))											//если название месяца это его порядковый
	{				
		if (strlen(month) == 1)													//номер, то присваиваем его указателю
			ptmonth[0] = month[0];
		else
		{
			ptmonth[0] = month[0];
			ptmonth[1] = month[1];
		}
		ptmonth[strlen(month) + 1] = '\0';
	}
	
	if ((strlen(month) < 3))											//если название месяца это его порядковый
	{																	//номер
		for (int i = 0; i < pt_year[11].number; i++)
		{
			if (pt_year[i].number < atoi(ptmonth))
			{
				days += pt_year[i].days;
				continue;
			}
			else
			{
				if (pt_year[i].days < day)
				{
					printf("В месяце %s нет %d дней(дня), в нем всего %d день(дней, дня).\n", pt_year[i].name, day, pt_year[i].days);
					printf("Введите верное количество дней для месяца %s.\n", pt_year[i].name);
					return 0;
				}
				days += day;
				check = days;
				break;
			}
		}
	}
	else if ((strlen(month) == 3))										//если название месяца это аббревиатура
	{
		for (int i = 0; i < pt_year[11].number; i++)
		{
			if (strcmp(pt_year[i].abbr, ptmonth))
			{
				days += pt_year[i].days;
				continue;
			}
			else
			{
				if (pt_year[i].days < day)
				{
					printf("В месяце %s нет %d дней(дня), в нем всего %d день(дней, дня).\n", pt_year[i].name, day, pt_year[i].days);
					printf("Введите верное количество дней для месяца %s.\n", pt_year[i].name);
					return 0;
				}
				days += day;
				check = days;
				break;
			}
		}
	}
	else if ((strlen(month) > 3))										//если это полное название месяца
	{
		for (int i = 0; i < pt_year[11].number; i++)
		{
			if (strcmp(pt_year[i].name, ptmonth))
			{
				days += pt_year[i].days;
				continue;
			}
			else
			{
				if (pt_year[i].days < day)
				{
					printf("В месяце %s нет %d дней(дня), в нем всего %d день(дней, дня).\n", pt_year[i].name, day, pt_year[i].days);
					printf("Введите верное количество дней для месяца %s.\n", pt_year[i].name);
					return 0;
				}
				days += day;
				check = days;
				break;
			}
		}
	}

	free(ptmonth);														//освобождаем память

	return check;
}