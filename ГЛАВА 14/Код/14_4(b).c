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

void show(struct id five);

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
	
	for (int i = 0; i < 5; i++)
		show(five[i]);

	return 0;
}

void show(struct id five)
{
	printf("%s, %s ", five.man.last_name, five.man.first_name);
	if (strlen(five.man.patronymic) > 0)
		printf("%c. ", five.man.patronymic[0]);
	printf("-- %d\n", five.number);
}