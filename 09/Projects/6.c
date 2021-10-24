#include <stdio.h>

int power(int x, int p);
int polynomial(int x);

int main(void)
{
    int x;

    printf("Enter value of x: ");
    scanf("%d", &x);

    printf("Result: %d\n", polynomial(x));

    return 0;
}

int power(int x, int p)
{
    int result = x;

    while (--p)
    {
        result *= x;
    }
    return result;
}

int polynomial(int x)
{
    int result = 0;

    result += 3*power(x, 5) + 2*power(x, 4) - (5*power(x, 3)) - power(x, 2);
    result += 7*x - 6;

    return result;
}
