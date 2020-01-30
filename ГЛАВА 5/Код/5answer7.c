#include <stdio.h>
#define FORMAT "%s! C is cool!\n"
int main(void)
{

	printf(FORMAT, FORMAT);
	printf("%s! C is cool!\n", "%s! C is cool!\n");
	return 0;
}