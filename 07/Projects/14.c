#include<stdio.h>
#include<math.h>

int main(void)
{
    float x;
    double y, y_old;
    double average, division;

    printf("Enter a positive number: ");
    scanf("%f", &x);

    y = 1;

    do
    {
        y_old = y;
        division = x / y;
        average = (y + division) / 2;
        y = average;
    }
    while (fabs(y_old - y) >= y * 1e-5);

    printf("Square root: %.5f\n", average);

    return 0;
}
