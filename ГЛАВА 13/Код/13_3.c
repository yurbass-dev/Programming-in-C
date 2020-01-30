#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 256
#define SIZE_NAME 81

void TOUPPER(char *pt_arr, int size);

int main(void)
{
    FILE *in;
    FILE *out;
    char array[SIZE];
    char in_name[SIZE_NAME];
    char out_name[SIZE_NAME];
    
    printf("Введите имя исходного файла:\n");
    scanf("%s", in_name);
    printf("А теперь введите имя выходного файла:\n");
    scanf("%s", out_name);
    
    if ((in = fopen(in_name, "r")) == NULL)
    {
        fprintf(stderr, "Не удалось открыть файл %s.\n", in_name);
        exit(EXIT_FAILURE);
    }
    else if ((out = fopen(out_name, "w")) == NULL)
    {
        fprintf(stderr, "Не удалось открыть файл %s.\n", out_name);
        exit(EXIT_FAILURE);
    }
    
    while (!feof(in))
    {
        if (fgets(array, SIZE, in))
        {
            TOUPPER(array, SIZE);
            fputs(array, out);
        }
    }
    if (fclose(in) != 0)
        fprintf(stderr, "Не удается закрыть файл %s.\n", in_name);
    if (fclose(out) != 0)
        fprintf(stderr, "Не удается закрыть файл %s.\n", out_name);
    
    puts("Программа завершена!");
    
    return 0;
}

void TOUPPER(char *pt_arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (pt_arr[i] != '\n')
            pt_arr[i] = toupper(pt_arr[i]);
    }
}

