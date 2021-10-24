#include<stdio.h>

int main(void)
{
    int factorial;
    float e = 1.0f, term, small;

    printf("Insert a small number: ");
    scanf("%f", &small);

    for (int i = 1;; i++)
    {
        factorial = 1;
        for (int j = 1; j <= i; j++)
        {
            factorial *= j;
        }

        term = 1.0f / factorial;
        if (term < small)
            break;
        e += 1.0f / factorial;
    }

    printf("The value of e is %.4f\n", e);

    return 0;
}
