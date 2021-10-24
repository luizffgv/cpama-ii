#include<stdio.h>

int main(void)
{
    int n, max, square;

    printf("Enter a number: ");
    scanf("%d", &max);

    square = 0;
    for (n = 2; (square = n * n) <= max; n += 2)
        printf("%d\n", square);

    return 0;
}
