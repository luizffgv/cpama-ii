#include <stdio.h>

int main(void)
{
    int y, x;
    int oy, ox;
    int i;
    int n;

    printf("This program creates a magic square of a specified size.\n"
           "The size must be an odd number between 1 and 99.\n"
           "Enter size of magic square: ");
    scanf("%d", &n);

    int square[n][n];
    for (y = 0; y < n; y++)
        for (x = 0; x < n; x++)
            square[y][x] = 0;

    i = 1;
    y = 0;
    x = n / 2;
    square[y][x] = i;
    while (++i <= n * n)
    {
        oy = y;
        ox = x;
        y = (y == 0) ? n-1 : y-1;
        x = (x == n-1) ? 0 : x+1;
        if (square[y][x] != 0)
        {
            y = ++oy;
            x = ox;
        }

        square[y][x] = i;
    }

    for (y = 0; y < n; y++)
    {
        for (x = 0; x < n; x++)
            printf("%5d", square[y][x]);
        printf("\n");
    }

    return 0;
}
