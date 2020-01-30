#include <stdio.h>
#include <string.h>		//for strlen()
#include <stdlib.h>		//for malloc()
#include <ctype.h>		//for touuper(), tolower()

struct month 
{
	char name[10];
	char abbr[4];
	int days;
	int number;
};

struct month all_months[12] = 
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

int count_days(const char * month);

int main(void)
{
	int days;
	char month[10];

	printf("Введите название месяца для подсчета дней:\n");

	while (scanf("%s", month) && month[0] != 'q')
	{
		if ((days = count_days(month)))
			printf("Количество дней %d.\n", days);
		else
			printf("Введите верно имя месяца.\n");
		printf("Введите название месяца для подсчета дней (q для выхода)\n");
	}
	printf("Программа завершена!\n");

	return 0;
}

int count_days(const char * month)
{
	extern struct month all_months[];
	int days = 0;
	int check = 0;
	char * pmonth = (char *) malloc(strlen(month) + 1);

	pmonth[0] = toupper(month[0]);

	for (int i = 1; month[i] != '\0'; i++)
	{
		pmonth[i] = tolower(month[i]);
	}
	pmonth[strlen(month) + 1] = '\0';

	for (int i = 0; i < all_months[11].number; i++)
	{
		
		if (strcmp(all_months[i].name, pmonth))
		{
			days += all_months[i].days;
			continue;
		}
		else
		{
			days += all_months[i].days;
			check = days;
			break;
		}
	}
	free(pmonth);

	return check;
}