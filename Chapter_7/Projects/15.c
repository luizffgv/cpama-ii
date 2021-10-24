#include<stdio.h>

int main(void)
{
    int num;
    int num_temp;
    long double num_factorial = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    for (num_temp = num; num_temp > 0; num_factorial *= num_temp--);

    printf("Factorial of %d: %Lf\n", num, num_factorial);

    return 0;
}

/*
    short:          works up to 7.
    int:            works up to 12.
    long:           works up to 20.
    long long:      same as long.
    float:          works up to 34 - rest is inf.
    double:         works up to 170 - rest is inf.
    long double:    works up to 1754 - rest is inf.
*/
