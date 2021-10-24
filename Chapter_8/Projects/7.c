#include <stdio.h>

int main(void)
{
    int array[5][5];
    int sum;

    for (int row = 0; row < 5; row++)
    {
        printf("Enter row %d: ", row+1);
        for (int column = 0; column < 5; column++)
            scanf("%d", &array[row][column]);
    }

    printf("\nRow totals:");
    for (int row = 0; row < 5; row++)
    {
        sum = 0;
        for (int column = 0; column < 5; column++)
        {
            sum += array[row][column];
        }
        printf("%3d", sum);
    }

    printf("\nColumn totals:");
    for (int column = 0; column < 5; column++)
    {
        sum = 0;
        for (int row = 0; row < 5; row++)
        {
            sum += array[row][column];
        }
        printf("%3d", sum);
    }
    printf("\n");

    return 0;
}
