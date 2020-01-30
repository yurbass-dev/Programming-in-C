
#include <stdio.h>
#include <stdlib.h>


void init_nums(int row, int cols, int ar[row][cols], FILE *fp);
void init_symb(int row, int cols, int num_ar[row][cols], char symb_ar[row][cols + 1], char symbols[]);

int main(void)
{
    FILE *src;
    FILE *dest;
    int index;
    int row = 20;
    int cols = 30;
    int num_ar[row][cols];
    char symb_ar[row][cols + 1];
    char f_name1[31];
    char f_name2[31];
    char symbols[10] = {' ', '.', '^', ':', '~', '*', '=', '+', '%', '#'};
    
    printf("Введите имя файла, значение которого нужно считать:\n");
    scanf("%s", f_name1);
    
    if ((src = fopen(f_name1, "r")) == NULL)
    {
        fprintf(stderr, "Не удалось открыть файл %s.\n", f_name1);
        exit(EXIT_FAILURE);
    }
    
    init_nums(row, cols, num_ar, src);

    
    printf("Введите имя файла, куда хотите сохранить значения:\n");
    scanf("%s", f_name2);
    putchar('\n');
    
    if ((dest = fopen(f_name2, "w")) == NULL)
    {
        fprintf(stderr, "Не удалось открыть файл %s.\n", f_name2);
        exit(EXIT_FAILURE);
    }
    init_symb(row, cols, num_ar, symb_ar, symbols);

  
    
    for (int i = 0; i < 20; i++)
    {
        puts(symb_ar[i]);
        fprintf(dest, "%s\n", symb_ar[i]);
        
    }
    
    if (fclose(src) != 0)
    {
        fprintf(stderr, "Не удалось закрыть файл %s.\n", f_name1);
    }
    if (fclose(dest) != 0)
    {
        fprintf(stderr, "Не удалось закрыть файл %s.\n", f_name2);
    }
    putchar('\n');
    puts("Программа завершена!");
    
    return 0;
}

void init_nums(int row, int cols, int ar[row][cols], FILE *fp)
{
    for (int i = 0; i < row && !feof(fp); i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fscanf(fp, "%d", &ar[i][j]);
        }
    }
}

void init_symb(int row, int cols, int num_ar[row][cols], char symb_ar[row][cols + 1], char symbols[])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols + 1; j++)
        {
            if (j == 30)
            {
                symb_ar[i][j] = '\0';
            }
            else
            {
                symb_ar[i][j] = symbols[num_ar[i][j]];
            }
            
        }
    }
}
