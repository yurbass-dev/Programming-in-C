/* pe14-8.c */ 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#define LEN 14 
#define SEATS 12 
#define EMPTY 0 
#define TAKEN 1 
#define CONTINUE 1 
#define DONE 0 
struct planestats {
	int seat_id; 
	int status; 
	char last[LEN]; 
	char first[LEN];
};

int getmenu(void);
int getlet(const char *);
int openings(const struct planestats [], int);
void show_empties(const struct planestats [], int); void list_assign(struct planestats *[], int);
void assign_seat(struct planestats [], int);
void delete_seat(struct planestats [], int);
void show_seats(const struct planestats [], int);
void sort(struct planestats *[], int);
void makelist(const struct planestats [], char *, int); char * s_gets(char * st, int n);
int main(void)
{
	struct planestats plane_1[SEATS], *ps[SEATS]; 
	int choice;
	int i;
	FILE *fp;
	size_t size = sizeof(struct planestats); 
	for(i=0;i<SEATS;i++)
		ps[i] = &plane_1[i];
	if ((fp = fopen("air.dat", "rb")) == NULL )
		for(i=0;i<SEATS;i++) 
		{
			plane_1[i].status = EMPTY;
			plane_1[i].seat_id = i + 1; 
		}
	else 
	{
		fread(plane_1, size, SEATS, fp);
		fclose(fp); 
	}
	while ( (choice = getmenu() ) != 'q') 
	{
		switch (choice) 
		{
			case 'o' : printf("Количество свободных мест: %d.\n", 
						openings(plane_1, SEATS));
						break;
			case 'e' : show_empties(plane_1, SEATS);
						break;
			case 'l' : list_assign(ps, SEATS);
						break;
			case 'a' : assign_seat(plane_1, SEATS);
						break;
			case 'd' : delete_seat(plane_1, SEATS);
						break;
			default : puts("Проблема в операторе switch.");
						break;
		} 
	}
	if((fp = fopen("air.dat", "wb")) == NULL ) 
		puts("Не удается сохранить данные в файл.");
	else 
	{
		fwrite(plane_1, size, SEATS, fp);
		fclose(fp); 
	}
	puts("Программа завершена.");

	return 0; 
}

#define CHOICES 6
int getmenu(void) 
{
	const char *descript[CHOICES] = 
	{
		"Показать количество свободных мест",
		"Показать список свободных мест",
		"Показать список забронированных мест в алфавитном порядке", 
		"Забронировать место для пассажира",
		"Снять броню с места",
		"Выйти из программы"
	};
	const char labels[CHOICES + 1] = "oeladq";
	int i;
	puts("Для выбора функции введите ее буквенную метку:"); 
	for (i = 0; i < CHOICES; i++)
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
int openings(const struct planestats pl[], int n) 
{
	int count = 0;
	int seat;
	for (seat = 0; seat < n; seat++)
		if (pl[seat].status == EMPTY) 
			count++;
	return count; 
}
void show_empties(const struct planestats pl[], int n) 
{
	char seating[3* SEATS]; 
	if (openings(pl,n) == 0)
		puts("Все места забронированы."); 
	else
	{
		puts("Свободны следующие места:"); 
		makelist(pl, seating, EMPTY); 
		puts(seating);
	} 
}
void makelist(const struct planestats pl[], char * str, int kind) 
{
	int seat;
	char temp[LEN];
	str[0] = '\0';
	for (seat = 0; seat < SEATS; seat++)
		if (pl[seat].status == kind) 
		{
			sprintf(temp," %d", pl[seat].seat_id);
			strcat(str, temp); 
		}
}

void list_assign(struct planestats *ps[], int n) {
int i;
if (openings(*ps, n) == SEATS)
puts("Все места свободны."); else
{
sort(ps, n);
for(i = 0; i < SEATS; i++)
if ( ps[i]->status == TAKEN )
printf ("Место %d: %s, %s\n", ps[i]->seat_id, ps[i]->last, ps[i]->first);
} }
void assign_seat(struct planestats pl[], int n) {
char list[3 * SEATS]; int seat, loop;
if (openings(pl,n) == 0)
puts("Все места забронированы."); else
{
makelist(pl,list, EMPTY);
puts("Какое место вас интересует? Выберите из следующего списка:"); puts(list);
do
{
while( scanf("%d", &seat) != 1) {
scanf("%*s");
puts("Введите число из этого списка:"); puts(list);
} if(seat<1||seat>SEATS||
pl[seat-1].status == TAKEN) {
puts("Введите число из этого списка:"); puts(list);
loop = CONTINUE;
} else
loop = DONE;
} while (loop == CONTINUE); while (getchar() != '\n')
continue;
puts("Введите имя:");
s_gets(pl[seat - 1].first, LEN);
puts("Введите фамилию:");
s_gets(pl[seat - 1].last, LEN);
printf("Для %s %s бронируется место %d.\n",
pl[seat - 1].first, pl[seat - 1].last, seat);
puts("Введите a, чтобы принять броню, или c, чтобы отменить бронирование."); if (getlet("ac") == 'a')
{
pl[seat - 1].status = TAKEN;
puts("Место для пассажира забронировано."); }
else
puts("Место для пассажира не забронировано.");
} }

void delete_seat(struct planestats pl[], int n) {
int seat, loop;
char list[3 * SEATS];
if (openings(pl, n) == SEATS)
puts("Все места уже свободны."); else
{
show_seats(pl, n);
makelist(pl, list, TAKEN);
puts("Введите номер места, с которого должна быть снята броня:"); do
{
while( scanf("%d", &seat) != 1) {
scanf("%*s");
puts("Введите число из этого списка:"); puts(list);
} if(seat<1||seat>SEATS||
pl[seat-1].status == EMPTY) {
puts("Введите число из этого списка:"); puts(list);
loop = CONTINUE;
} else
loop = DONE;
} while (loop == CONTINUE); while (getchar() != '\n')
continue;
printf("Для %s %s снимается броня с места %d.\n",
pl[seat - 1].first, pl[seat - 1].last, seat);
puts("Введите d, чтобы снять броню, или a, чтобы отменить снятие."); if (getlet("da") == 'd')
{
pl[seat - 1].status = EMPTY;
puts("Броня для пассажира снята."); }
else
puts("Броня для пассажира оставлена.");
} }

void show_seats(const struct planestats pl[], int n) {
int i;
puts("Места, которые в настоящее время забронированы:"); for(i=0;i<SEATS;i++)
if (pl[i].status == TAKEN)
printf("Место %d: %s, %s\n", pl[i].seat_id, pl[i].last, pl[i].first);
}
void sort(struct planestats *array[], int limit) {
int top, search;
struct planestats * temp;
for (top = 0; top < limit -1; top++)
for (search = top + 1; search < limit; search++)
if (strcmp(array[search]->last, array[top]->last) < 0) {
temp = array[search]; array[search] = array[top]; array[top] = temp;
} }
char * s_gets(char * st, int n) {
char * ret_val;
char * find;
ret_val = fgets(st, n, stdin); if (ret_val)
{
find = strchr(st, '\n'); // поиск новой строки
if (find) // если адрес не равен NULL,
*find = '\0'; // поместить туда нулевой символ else
}
return ret_val; }