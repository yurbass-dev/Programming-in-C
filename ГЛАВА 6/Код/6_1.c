#include <stdio.h>
int main(void)
{
	char ch[26];
	int i, j;

	for(i = 0; i < 26; i++)
		ch[i] = i + 'a';
	for(j = 0; j < 26; j++)
		printf(" %c", ch[j]);
	printf("\n");

	return 0; 
}