#include <stdio.h>
#include <string.h>
int main(void)
{
    char line[255];
    int i, size, end;

    printf("Введите строку для вывода ее в обратном порядке (после ввода, нажмите 0):\n");

    for (i = 0; scanf("%c", &line[i]), line[i] != '\n'; i++)

    size = strlen(line);

    for (i = size; i >= 0; i--)
        printf("%c", line[i]);

    printf("\n");
      
    return 0;
}