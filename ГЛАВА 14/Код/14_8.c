#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LEN 30					//длина имени и фамилии
#define STS 12					//количество мест в самолете

void show_menu(void);
void count_free_seats(struct avia const * pst, int seats);
void list_free_seats(struct avia const * pst, int seats);
void booked_seats_alphabet(struct avia const * pst, int seats);
char * s_gets(char * st, int n);
void booking_seat(struct avia * pst, int seats);
void remove_booking(struct avia * pst, int seats);

struct avia 
{
	int num_seat;				//номер места
	int check_seat;				//маркер проверки брони места (0 - свободно, 1 - занято)
	char first_name[LEN];
	char last_name[LEN];
};

int main(void)
{
	struct avia * p_st = NULL;
	FILE *ptf;
	int ch;
	int seat;
	int i;
	bool exitCase = true;
	size_t size = sizeof(struct avia);

	//Выделяем память под массив из 12-ти структур типа avia и инициализируем все биты нулями 
	//(для того, чтобы знать занято место или свободно)
	p_st = (struct avia *) calloc(STS, sizeof(struct avia));
	if (p_st == NULL)
		exit(EXIT_FAILURE);
	
	if ((ptf = fopen("colossus", "r+")) == NULL)
	{
		fprintf(stderr, "Не удалось открыть файл %s.\n", "colossus");
		exit(EXIT_FAILURE);
	}
	
	//Проверка пуст ли файл
	if ((ch = fgetc(ptf)) && (isdigit(ch)))
	{
		rewind(ptf);
		for (i = 0; i < STS; i++)
		{
			fscanf(ptf, "%d %d %s %s", &p_st[i].num_seat, &p_st[i].check_seat, p_st[i].first_name, 
										   p_st[i].last_name);
		}

		/*
		// Считываем данные (только те места, которые забронированы) из файла в массив структур
		while ((ch = fgetc(ptf)) && ch != EOF)
		{	
			fgetc(ptf);
			ch = fgetc(ptf);
			// Если место не забронировано, то просто считываем строку до появления символа новой строки
			// или если это последняя строка то, до конца файла.
			if (ch == '0')
			{
				while ((ch = fgetc(ptf)) && ch != '\n' && ch != EOF)
					continue;
				continue;
			}
			else if (ch != EOF)
			{
				fseek(ptf, -3L, SEEK_CUR);	// Перемещаем указатель в файле в начало строки
				fscanf(ptf, "%d", &seat);
				fscanf(ptf, "%d %s %s", &p_st[seat - 1].check_seat, p_st[seat - 1].first_name, 
										   p_st[seat - 1].last_name);
				ch = fgetc(ptf);
				if (ch == EOF)
					break;
			}
		}
		*/
	}
	else
	{
		//Присваивем номер места каждой структуре
		for (i = 0; i < STS; i++)
		{
			p_st[i].num_seat = i + 1;
			if (p_st[i].check_seat == 0)
			{
				strcpy(p_st[i].first_name, "-");
				strcpy(p_st[i].last_name, "-");
			}
		} 
	}
	

	show_menu();
	while (exitCase && (ch = getchar()))
	{
		while(getchar() != '\n')
			continue;
		switch (ch)
		{
			case 'a':
				count_free_seats(p_st, STS);
				putchar('\n');
				show_menu();
				break;
			case 'b':
				list_free_seats(p_st, STS);
				putchar('\n');
				show_menu();
				break;
			case 'c':
				booked_seats_alphabet(p_st, STS);
				putchar('\n');
				show_menu();
				break;
			case 'd':
				booking_seat(p_st, STS);
				putchar('\n');
				show_menu();
				break;
			case 'e':
				remove_booking(p_st, STS);
				putchar('\n');
				show_menu();
				break;
			case 'f':
				printf("Программа завершена!\n");
				exitCase = false;
				break;
			default :
				printf("Введите буквенную метку функции (a, b, c, d, e, f).\n");
				break;
		}
	}
	
	
	
	rewind(ptf);
	for (i = 0; i < STS; i++)
	{
		fprintf(ptf, "%d %d %s %s\n", p_st[i].num_seat, p_st[i].check_seat, p_st[i].first_name,
									  p_st[i].last_name);
	}

	free(p_st);
	if (fclose(ptf) != 0)
	{
		fprintf(stderr, "Не удалось закрыть файл %s.\n", "colossus");
		exit(1);
	}

	return 0;
}

void show_menu(void)
{
	puts("Для выбора функции введите ее буквенную метку:");
	puts("а) Показать количество свободных мест");
	puts("b) Показать список свободных мест");
	puts("c) Показать список забронированных мест в алфавитном порядке");
	puts("d) Забронировать место для пассажира");
	puts("e) Снять броню с места");
	puts("f) Выйти из программы");
	putchar('\n');
}

void count_free_seats(struct avia const * pst, int seats)
{
	int free_seats = 0;

	for (int i = 0; i < seats; i++)
	{
		if (pst[i].check_seat == 0)
			free_seats++;
	}
	printf("Свободных мест на борту самолета: %d.\n", free_seats);
}

void list_free_seats(struct avia const * pst, int seats)
{
	bool check = true;
	printf("Список свободных мест: ");
	for (int i = 0; i < seats; i++)
	{
		if (pst[i].check_seat == 0)
		{
			check = false;
			printf(" %d", pst[i].num_seat);
		}
	}
	if (check)
		printf("(все места заняты)");
	printf(".\n");
}

void booked_seats_alphabet(struct avia const * pst, int seats)
{
	struct avia const * alphabet[seats];		// Массив указателей на структуру avia (для сортировки указателей)
	struct avia const * temp_st;				// Временный указатель на структуру avia 
	int booked_seats = 0;						// Количество забронированных мест
	int i, j;	
	bool check = true;			

	for (i = 0; i < seats; i++)
	{
		if (pst[i].check_seat == 1)
			check = false;
	}
	if (check)
	{
		printf("Забронированных мест нету.\n");
	}
	else
	{
		// Находим забронированные места и присваиваем его адрес массиву указателей 
		for (i = 0, j = 0; i < seats; i++)
		{
			if (pst[i].check_seat == 1)
			{
				alphabet[j] = &pst[i];
				booked_seats++;
				j++; 
			}
		}
		// Сортировка по фамилии пузирьком
		for(i = 1; i < booked_seats; i++)
		{
	       for(j = 0; j < booked_seats - i; j++)
	       {
	           if(strcmp(alphabet[j]->last_name, alphabet[j + 1]->last_name) > 0)
	           {
	           		temp_st = alphabet[j];
	           		alphabet[j] = alphabet[j + 1];
	           		alphabet[j + 1] = temp_st;
	           }
	       }
		}
		// Выводим список забронированных мест
		printf("Список забронированных мест в алфавитном порядке:\n");
		for (i = 0; i < booked_seats; i++)
		{
			printf("%d %s %s\n", alphabet[i]->num_seat, alphabet[i]->first_name, alphabet[i]->last_name);
		}
	}
}

void booking_seat(struct avia * pst, int seats)
{
	int seat;
	bool check = true;
	int i;

	// Если свободных мест нету, перейти в главное меню
	for (i = 0; i < seats; i++)
	{
		if (pst[i].check_seat == 0)
		{
			check = false;
		}
	}
	if (check)
	{
		printf("Нету свободных мест!\n");
	}
	else
	{
		list_free_seats(pst, seats);
		// Запрашиваем номер места
		printf("Выберите место для бронирования (q для отмены): "); 
		while(scanf("%d", &seat) == 1)
		{
			if (seat < 1 || seat > seats)
			{
				printf("Введите число от 1 до %d: ", seats);
				continue;
			}
			check = true;
			while(getchar() != '\n')
				continue;
			// Проверяем занято ли выбраное место
			for (i = 0; i < seats; i++)
			{
				if (pst[i].num_seat == seat)
				{
					if (pst[i].check_seat == 1)
					{
						printf("Выберите свободное место для бронирования (q для отмены): ");
						check = false;
						break;
					}
				}
			}
			if (check)
			{
				pst[seat - 1].check_seat = 1;

				printf("Введите имя пассажира для бронирования места \n");
				printf("(нажмите [enter] в начале строки, чтобы закончить ввод):\n");
				while(s_gets(pst[seat - 1].first_name, LEN) != NULL && pst[seat - 1].first_name[0] != '\0')
				{
					printf("Теперь введите фамилию пассажира:\n");
					s_gets(pst[seat - 1].last_name, LEN);
					break;
				}
				break;
			}
		}
		while(getchar() != '\n')
				continue;
	}
}

void remove_booking(struct avia * pst, int seats)
{
	int seat;
	bool check = true;
	int i;

	// Если забронированых мест нету, перейти в главное меню
	for (i = 0; i < seats; i++)
	{
		if (pst[i].check_seat == 1)
		{
			check = false;
		}
	}
	if (check)
	{
		printf("Забронированых мест нету.\n");
	}
	else
	{
		printf("Список забронированных мест: ");
		for (int i = 0; i < seats; i++)
		{
			if (pst[i].check_seat == 1)
			{
				printf(" %d", pst[i].num_seat);
			}
		}
		printf(".\n");

		printf("Выберите место, чтобы снять с него броню (q для отмены):\n");
		while(scanf("%d", &seat) == 1)
		{
			if (seat < 1 || seat > seats)
			{
				printf("Введите число от 1 до %d: ", seats);
				continue;
			}
			check = true;
			while(getchar() != '\n')
				continue;
			// Проверяем свободно ли выбраное место
			for (i = 0; i < seats; i++)
			{
				if (pst[i].num_seat == seat)
				{
					if (pst[i].check_seat == 0)
					{
						printf("Выберите забронированое место для снятия брони (q для отмены): ");
						check = false;
						break;
					}
				}
			}
			if (check)
			{
				pst[seat - 1].check_seat = 0;
				break;
			}
		}
		while(getchar() != '\n')
				continue;
	}
}

char * s_gets(char * st, int n) 
{
	char * ret_val; 
	char * find;
	ret_val = fgets(st, n, stdin); 
	if (ret_val)
	{
		find = strchr(st, '\n'); 
		if (find)
			*find = '\0'; 
		else
			while (getchar() != '\n') 
				continue;
	}
	return ret_val;
}

