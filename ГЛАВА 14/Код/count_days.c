#include <string.h>

extern struct all_months[];

int count_days(const char * month)
{
	int days = 0;

	for (int i = 0; i < all_month[11].number; i++)
	{
		if (strcmp(all_months.name, month))
		{
			days += all_month[i].days;
			continue;
		}
		else
		{
			days += all_month[i].days;
			break;
		}
	}

	return days;
}

