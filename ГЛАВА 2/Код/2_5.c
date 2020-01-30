#include <stdio.h>

void br(void);
void ic(void);

int main(void)
{
	printf("Бразилия, Россия, Индия, Китай\n");
	ic();
	br();

	return 0;
}

void br(void)
{
	printf("Бразилия, Россия\n");
}

void ic(void)
{
	printf("Индия, Китай,\n");
}