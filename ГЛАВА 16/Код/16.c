#include <stdio.h>
#define NEW(X) ((X) + 5)
#define LOWER(a, b) (a < b ? a : b)
#define SAMPLE(A, B) printf(#A " = %d и " #B " = %d\n", A, B);

int main(void)
{
	int a = 7;
	int b = 10;

	SAMPLE(3 + 4, 4 * 12);

	printf("%d\n", LOWER(a, b));

	a = b * NEW(-a);
	printf("a = %d\n", a);

	return 0;
}