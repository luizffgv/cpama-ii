#include <stdio.h>

int power(int x, int n);

int main(void)
{
    int number;
    int number_power;

    printf("Enter a number and a power: ");
    scanf("%d%d", &number, &number_power);

    printf("Result: %d\n", power(number, number_power));

    return 0;
}


int power(int x, int n)
{
    int result;

    if (n == 0) return 1;
    else if (n % 2 == 0)
    {
        result = power(x, n / 2);
        return result * result;
    }
    else
        return x * power(x, n - 1);
}