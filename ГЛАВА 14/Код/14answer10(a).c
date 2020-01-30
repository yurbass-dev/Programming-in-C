#include <stdio.h>

struct gas
{
	float distance;
	float gals;
	float mpg;
};

void find_mpg(struct gas * pstr);

int main(void)
{
	struct gas smpl = {200.0, 6.6};

	find_mpg(&smpl);

	printf("При дистанции %.1f миль и расходу топлива %.1f галлонов\n", smpl.distance, smpl.gals);
	printf("MpG равен %.1f.\n", smpl.mpg);

	return 0;
}

void find_mpg(struct gas * pstr)
{
	str->mpg = str->distance / str->gals;
}