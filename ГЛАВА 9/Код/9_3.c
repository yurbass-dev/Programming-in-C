#include <stdio.h>

void ch_maker_line(char, int, int);

int main(void)
{
    char ch;
    int symbols;
    int lines;

    printf("Please enter character: ");
    ch = getchar();

    while (getchar() != '\n')
        continue;

    printf("\nPlease enter count of chatacters: ");
    scanf("%d", &symbols);

    while (getchar() != '\n')
        continue;

    printf("\nPlease enter count of lines: ");
    scanf("%d", &lines);

    ch_maker_line(ch, symbols, lines);

    return 0;
}

void ch_maker_line(char ch, int symbols, int lines)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < symbols; j++)
            putchar(ch);
        putchar('\n');
    }
}