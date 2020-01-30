#include <stdio.h>

void save_arr(int rows, int cols, double arr[rows][cols]);
double average_for_each_set(double arr[], int n);
double average_of_all(int rows, int cols, double arr[rows][cols]);
double max_of_all(int rows, int cols, double arr[rows][cols]);

int main(void)
{
    int rows = 3;
    int cols = 5;
    double array[rows][cols];
    double aver_for_each_set;
    double aver_of_all;
    double max;
    
    save_arr(rows, cols, array);
    
    for (int row = 0; row < rows; row++)
    {
        printf("Среднее значение для %d-го набора: ", row + 1);
        aver_for_each_set = average_for_each_set(array[row], cols);
        printf("%g\n", aver_for_each_set);
    }
    
    aver_of_all = average_of_all(rows, cols, array);
    printf("Cреднее значение из всех значений: %g\n", aver_of_all);
    
    max = max_of_all(rows, cols, array);
    printf("Наибольшее значение из всех: %g\n", max);
    
    return 0;
}

void save_arr(int rows, int cols, double arr[rows][cols])
{
    printf("Введите три набора по пять чисел:\n");
    for (int row = 0; row < rows; row++)
    {
        printf("%d-й: ", row + 1);
        for (int col = 0; col < cols; col++)
        {
            scanf("%lf", &arr[row][col]);
        }
    }
}

double average_for_each_set(double arr[], int n)
{
    double average = 0.0;
    
    for (int i = 0; i < n; i++)
        average += arr[i];
    average /= n;
    
    return average;
}

double average_of_all(int rows, int cols ,double arr[rows][cols])
{
    double average = 0.0;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            average += arr[row][col];
        }
    }
    average /= (rows * cols);
    
    return average;
}

double max_of_all(int rows, int cols, double arr[rows][cols])
{
    double max = arr[0][0];
    
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (max < arr[row][col])
                max = arr[row][col];
        }
    }
    
    return max;
}

