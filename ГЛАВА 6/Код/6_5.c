#include <stdio.h>
int main(void)
{
	char ch;
	int i, j, k, v;

	printf("Введите английскую прописную букву.\n");
	scanf("%c", &ch);


	for(i = 'A'; i <= ch; i++)
	{
		for(j = 'A' + (ch - i); j > 'A'; j--)
			printf("\040");

		for(k = 'A'; k <= i; k++)
			printf("%c", k);

		for(v = i - 1; v >= 'A'; v--)
			printf("%c", v);
		
		printf("\n");
	}

	return 0;
}
