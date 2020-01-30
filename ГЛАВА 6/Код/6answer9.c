#include <stdio.h>
int main(void)
{
	int n;

	for (n = 1; n * n < 200; n += 4)
		printf("%d\n", n);

	return 0;
}