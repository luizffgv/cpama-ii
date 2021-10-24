#include<stdio.h>

int main(void)
{
    int n, m, num1, num2, gcd, remainder;

    printf("Enter a fraction: ");
    scanf("%d /%d", &num1, &num2);

    n = num1;
    m = num2;

    while (n != 0)
    {
        remainder = m % n;
        m = n;
        n = remainder;
    }
    gcd = m;

    printf("In lowest terms: %d/%d\n", num1 / gcd, num2 / gcd);

    return 0;
}
