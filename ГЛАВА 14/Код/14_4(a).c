#include <stdio.h>
#include <string.h>

struct full_name 
{
	char first_name[20];
	char patronymic[20];
	char last_name[20];
};

struct id
{
	int number;
	struct full_name man;
};

void show(struct id * five, int n);

int main(void)
{
	struct id five[5] = 
	{
		{1234567, "Igor", "Petrovich", "Ivanov"},
		{2345678, "Semen", "Olegovich", "Kirpa"},
		{3456789, "Oleg", "Anatolievich", "Suprun"},
		{4567891, "Petro", "", "Stolyar"},
		{5678912, "Stepan", "Andreevich", "Kuzin"}
	};
	show(&five[0], 5);

	return 0;
}

void show(struct id * str, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s, %s ", (str + i)->man.last_name, str[i].man.first_name);
		if (strlen(str[i].man.patronymic) > 0)
			printf("%c. ", str[i].man.patronymic[0]);
		printf("-- %d\n", str[i].number);
	}
}