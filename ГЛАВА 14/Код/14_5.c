#include <stdio.h>
#include <string.h>
#define CSIZE 4
#define LENGHT 20
#define GRADES 3

struct name
{
	char first_name[LENGHT];
	char last_name[LENGHT];
};

struct student
{
	struct name man;
	float grade[GRADES];
	float aver_grade;
};

void get_grade(struct student * grp, int size);
void av_grade(struct student * grp, int size);
void show_group(const struct student * grd, int size);

int main(void)
{
	struct student group[CSIZE] =
	{
		{"Kevin", "Speicy"},
		{"Steven", "Spilberg"},
		{"Patrick", "Joybet"},
		{"Oliver", "Hunter"}
	};

	get_grade(&group[0], CSIZE); 
	av_grade(&group[0], CSIZE);
	show_group(&group[0], CSIZE);
	puts("Программа завершена!\n");

	return 0;
}

void get_grade(struct student * grp, int size)
{
	char name[LENGHT];
	int index = 0;
	int check = 0;

	printf("Введите имя студента:\n");
	while (scanf("%s", name) && check != size)
	{
		while (index < size)
		{
			if (strcmp(grp[index].man.first_name, name) == 0)
			{
				check++;
				break;
			}
			index++;
		}
		if (index == size)
		{
			printf("Студента с именем %s нету в списке.\n", name);
			printf("Введите верно имя студента:\n");
			index = 0;
		}
		if (check)
		{
			printf("Теперь введите %d оценки студента %s:\n", GRADES, name);
			for (int i = 0; i < GRADES; i++)
			{
				scanf("%f", &grp[index].grade[i]);
			}
			if (check == size)
				break;
			printf("Введите имя следующего студента:\n");
			index = 0;
		}
	}
}

void av_grade(struct student * grp, int size)
{
	float summ = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < GRADES; j++)
		{
			summ += grp[i].grade[j];
		}
		grp[i].aver_grade = summ / GRADES;
		summ = 0;
	}
}

void show_group(const struct student * grd, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("Студент %s %s имеет оценки:\n", grd[i].man.first_name, grd[i].man.last_name);
		for (int j = 0; j < GRADES; j++)
		{
			printf("%.2f ", grd[i].grade[j]);
		}
		putchar('\n');
		printf("Средний балл равен %.2f.\n", grd[i].aver_grade);
	}
}
