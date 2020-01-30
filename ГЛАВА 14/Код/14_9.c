#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LEN 30					// длина имени и фамилии
#define SEATS 12				// количество мест в самолете

void make_ptr(struct avia *p_flight, struct avia *p_pst[], int seats);
void free_markers(struct avia *pst, int seats);
void write_data(FILE *fp, struct avia *pst[], int seats, int size);
int getlet(const char * s);
int main_menu(void);
int getmenu(void);
void count_free_seats(struct avia const * pst, int seats);
void list_free_seats(struct avia const * pst, int seats);
void booked_seats_alphabet(struct avia const * pst, int seats);
void booking_seat(struct avia * pst, int seats);
void remove_booking(struct avia * pst, int seats);
void confirm_booking(struct avia * pst, int seats);
char * s_gets(char * st, int n);


struct avia 
{
	int num_seat;				// номер места
	int check_seat;				// маркер проверки брони места (0 - свободно, 1 - занято)
	int confirm_booking;		// маркер подтверждения брони (0 - свободно, 1 - занято)
	char first_name[LEN];
	char last_name[LEN];
};

int main(void)
{
	struct avia flight_102[SEATS];
	struct avia flight_311[SEATS];
	struct avia flight_444[SEATS];
	struct avia flight_519[SEATS];
	struct avia * pst_102[SEATS];
	struct avia * pst_311[SEATS];
	struct avia * pst_444[SEATS];
	struct avia * pst_519[SEATS];
	struct avia * pst = NULL;
	FILE * fp;
	size_t size = sizeof(struct avia);
	int choice;
	int i;
	int num;
	const char *flight_str[4] =
	{
		"--------------Рейс 102---------------",
		"--------------Рейс 311---------------",
		"--------------Рейс 444---------------",
		"--------------Рейс 519---------------"
	};

	// Делаем массивы указателей на массивы структур типа avia
	make_ptr(flight_102, pst_102, SEATS);
	make_ptr(flight_311, pst_311, SEATS);
	make_ptr(flight_444, pst_444, SEATS);
	make_ptr(flight_519, pst_519, SEATS);

	if ((fp = fopen("colossus.dat", "rb")) == NULL)
	{
		free_markers(flight_102, SEATS);
		free_markers(flight_311, SEATS);
		free_markers(flight_444, SEATS);
		free_markers(flight_519, SEATS);
	}
	else
	{
		fread(flight_102, size, SEATS, fp);
		fread(flight_311, size, SEATS, fp);
		fread(flight_444, size, SEATS, fp);
		fread(flight_519, size, SEATS, fp);
		/*
		for (i = 0; i < SEATS; i++)
		{
			fscanf(fp, "%d %d %d %s %s", &flight_102[i].num_seat, &flight_102[i].check_seat, &flight_102[i].confirm_booking, 
											flight_102[i].first_name, flight_102[i].last_name);
		}
		for (i = 0; i < SEATS; i++)
		{
			fscanf(fp, "%d %d %d %s %s", &flight_311[i].num_seat, &flight_311[i].check_seat, &flight_311[i].confirm_booking, 
											flight_311[i].first_name, flight_311[i].last_name);
		}
		for (i = 0; i < SEATS; i++)
		{
			fscanf(fp, "%d %d %d %s %s", &flight_444[i].num_seat, &flight_444[i].check_seat, &flight_444[i].confirm_booking, 
											flight_444[i].first_name, flight_444[i].last_name);
		}
		for (i = 0; i < SEATS; i++)
		{
			fscanf(fp, "%d %d %d %s %s", &flight_519[i].num_seat, &flight_519[i].check_seat, &flight_519[i].confirm_booking, 
											flight_519[i].first_name, flight_519[i].last_name);
		}
		*/
		fclose(fp);
	}

	while ((choice = main_menu()) != 'q')
	{
		switch (choice)
		{
			case 'a':
				pst = pst_102[0];
				num = 0;
				break;
			case 'b':
				pst = pst_311[0];
				num = 1;
				break;
			case 'c':
				pst = pst_444[0];
				num = 2;
				break;
			case 'd':
				pst = pst_519[0];
				num = 3;
				break;
			default :
			 	printf("Проблема в операторе switch.\n");
				break;
		}

		while ((puts(flight_str[num])) && (choice = getmenu()) != 'g')
		{
			switch (choice)
			{
				case 'a':
					count_free_seats(pst, SEATS);
					putchar('\n');
					break;
				case 'b':
					list_free_seats(pst, SEATS);
					putchar('\n');
					break;
				case 'c':
					booked_seats_alphabet(pst, SEATS);
					putchar('\n');
					break;
				case 'd':
					booking_seat(pst, SEATS);
					putchar('\n');
					break;
				case 'e':
					confirm_booking(pst, SEATS);
					putchar('\n');
					break;
				case 'f':
					remove_booking(pst, SEATS);
					putchar('\n');
					break;
				default :
					printf("Проблема в операторе switch.\n");
					break;
			}
		}
	}

	if ((fp = fopen("colossus.dat", "wb")) == NULL)
		puts("Не удалось сохранить данные в файл.");
	else
	{
		fwrite(flight_102, size, SEATS, fp);
		fwrite(flight_311, size, SEATS, fp);
		fwrite(flight_444, size, SEATS, fp);
		fwrite(flight_519, size, SEATS, fp);
		/*
		for (i = 0; i < SEATS; i++)
		{
			fprintf(fp, "%d %d %d %s %s\n", flight_102[i].num_seat, flight_102[i].check_seat, flight_102[i].confirm_booking, 
											flight_102[i].first_name, flight_102[i].last_name);
		}
		for (i = 0; i < SEATS; i++)
		{
			fprintf(fp, "%d %d %d %s %s\n", flight_311[i].num_seat, flight_311[i].check_seat, flight_311[i].confirm_booking, 
											flight_311[i].first_name, flight_311[i].last_name);
		}
		for (i = 0; i < SEATS; i++)
		{
			fprintf(fp, "%d %d %d %s %s\n", flight_444[i].num_seat, flight_444[i].check_seat, flight_444[i].confirm_booking, 
											flight_444[i].first_name, flight_444[i].last_name);
		}
		for (i = 0; i < SEATS; i++)
		{
			fprintf(fp, "%d %d %d %s %s\n", flight_519[i].num_seat, flight_519[i].check_seat, flight_519[i].confirm_booking, 
											flight_519[i].first_name, flight_519[i].last_name);
		}
		*/
		fclose(fp);
	}


	puts("Программа завершена!");

	return 0;
}

void make_ptr(struct avia *p_flight, struct avia *p_pst[], int seats)
{
	for (int i = 0; i < seats; i++)
	{
		p_pst[i] = &p_flight[i];
	}
}

void free_markers(struct avia *pst, int seats)
{
	for (int i = 0; i < seats; i++)
	{
		pst[i].num_seat = i + 1;
		pst[i].check_seat = 0;
		pst[i].confirm_booking = 0;
		strcpy(pst[i].first_name, "-");
		strcpy(pst[i].last_name, "-");
	}
}

void write_data(FILE *fp, struct avia *pst[], int seats, int size)
{
	fwrite(pst, size, seats, fp);
}

#define CHOICES 7

int getmenu(void) 
{
	const char *descript[CHOICES] = 
	{
		"Показать количество свободных мест",
		"Показать список свободных мест",
		"Показать список забронированных мест в алфавитном порядке", 
		"Забронировать место для пассажира",
		"Подтвердить броню места",
		"Снять броню с места",
		"Вернуться в главное меню"
	};
	const char labels[CHOICES + 1] = "abcdefg";
	int i;
	puts("Для выбора функции введите ее буквенную метку:"); 
	for (i = 0; i < CHOICES; i++)
		printf("%c) %s\n", labels[i], descript[i]); 

	return getlet(labels);
}

int main_menu(void)
{
	const char *descript[CHOICES - 2] =
	{
		"Рейс 102",
		"Рейс 311",
		"Рейс 444",
		"Рейс 519",
		"Выйти из программы"
	};
	const char labels[CHOICES - 1] = "abcdq";
	int i;
	puts("Для выбора рейса введите его буквенную метку (q для выхода):"); 
	for (i = 0; i < CHOICES - 2; i++)
		printf("%c) %s\n", labels[i], descript[i]); 

	return getlet(labels);
}

int getlet(const char * s) 
{
	char c;

	c = getchar();
	while (strchr(s, c) == NULL) 
	{
		printf ("Введите символ из списка %s\n", s); 
		while (getchar() != '\n')
			continue; 
		c = getchar();
	}
	while (getchar() != '\n')
		continue; 

	return c;
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
			printf("%d %s %s", alphabet[i]->num_seat, alphabet[i]->first_name, alphabet[i]->last_name);
			if (alphabet[i]->confirm_booking == 1)
				printf(" - бронь подтверждена\n");
			else
				printf(" - нужно подтвердить бронь\n");
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
				pst[seat - 1].confirm_booking = 0;
				break;
			}
		}
		while(getchar() != '\n')
			continue;
	}
}

void confirm_booking(struct avia * pst, int seats)
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

		printf("Выберите место, чтобы подтвердить бронь (q для отмены):\n");
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
			// Проверяем не подтверждена ли бронь на выбраном место
			for (i = 0; i < seats; i++)
			{
				if (pst[i].num_seat == seat)
				{
					if (pst[i].confirm_booking == 1)
					{
						printf("Выберите другое место. Место %d имеет подтверждение брони (q для отмены): ", seat);
						check = false;
						break;
					}
				}
			}
			if (check)
			{
				pst[seat - 1].confirm_booking = 1;
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