#include<stdio.h>

int main(void)
{
    int n, factorial;
    float e = 1.0f;

    printf("Insert a number: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        factorial = 1;
        for (int j = 1; j <= i; j++)
        {
            factorial *= j;
        }

        e += 1.0f / factorial;
    }

    printf("The value of e is %.4f\n", e);

    return 0;
}
