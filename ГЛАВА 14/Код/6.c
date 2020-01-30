#include <stdio.h>

typedef struct lens
{
	float foclen;
	float fstop;
	char brand[30];
} LENS;

int main(void)
{	
	LENS array[10] = 
	{
		[2] = {500.0, 2.0, "Remarkatar"}
	};

	printf("%.1f %.1f %s\n", array[2].foclen, array[2].fstop, array[2].brand);

	return 0;
}


