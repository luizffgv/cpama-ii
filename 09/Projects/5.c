#include <stdio.h>

void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);

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

    char square[n][n];

    create_magic_square(n, square);
    print_magic_square(n, square);

    return 0;
}

void create_magic_square(int n, char magic_square[n][n])
{
    int i;
    int y, x, oy, ox;

    for (y = 0; y < n; y++)
        for (x = 0; x < n; x++)
            magic_square[y][x] = 0;

    i = 1;
    y = 0;
    x = n / 2;
    magic_square[y][x] = i;
    while (++i <= n * n)
    {
        oy = y;
        ox = x;
        y = (y == 0) ? n-1 : y-1;
        x = (x == n-1) ? 0 : x+1;
        if (magic_square[y][x] != 0)
        {
            y = ++oy;
            x = ox;
        }

        magic_square[y][x] = i;
    }
}

void print_magic_square(int n, char magic_square[n][n])
{
    int y, x;

    for (y = 0; y < n; y++)
    {
        for (x = 0; x < n; x++)
            printf("%5d", magic_square[y][x]);
        printf("\n");
    }
}