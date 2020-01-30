#include <stdio.h>
#define NUM_DANBAR 150
#define START_FRIENDS 5
int main(void)
{
	int friends = START_FRIENDS;
	int week, week_1;
	int friends_1; 

	for (week = 1; friends = (friends - week) * 2, friends < NUM_DANBAR; week++)
		printf("После %d недели у Профессора Робинса было %d друзей.\n", week_1 = week, friends_1 = friends);

	printf("%d друзей после %d недель, приближенно равно числу Данбара %d.\n", friends_1, week_1, NUM_DANBAR);

	return 0;
}
