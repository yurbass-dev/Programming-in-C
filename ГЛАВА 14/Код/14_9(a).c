#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LEN 30					// длина имени и фамилии
#define SEATS 12				// количество мест в самолете
#define FLIGHTS 4				// количество рейсов


struct avia 
{
	int num_seat;				// номер места
	int check_seat;				// маркер проверки брони места (0 - свободно, 1 - занято)
	int confirm_booking;		// маркер подтверждения брони
	char first_name[LEN];
	char last_name[LEN];
};

int main(void)
{
	struct avia planes[FLIGHTS][SEATS];
	struct avia (*pst)[FLIGHTS][SEATS] = &planes;
	FILE *fp;
	size_t size = sizeof(struct avia) * FLIGHTS;
	int ch;
	int i, j;

	
	for (i = 0; i < FLIGHTS; i++)
	{
		for (j = 0; j < SEATS; j++)
		{
			(*pst)[i][j] = planes[i][j];
		}
	}
	
	

	planes[0][1].num_seat = 7;
	
	printf("%d\n", (*pst)[0][1].num_seat);


	return 0;
}