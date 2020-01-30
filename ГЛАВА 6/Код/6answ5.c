#include <stdio.h>
int main(void)
{
	int a, b, list[10];

	for (a = 0; a < 10; a++)
	{
		list[a] = a + 1;
		
		for(b = 0; b <= a; b++)
			printf("%3d", list[b]);
		printf("\n");	
	}

	
	return 0;
}