#include<stdio.h>

int main(void)
{
    float speed;

    printf("Enter a wind speed (in knots): ");
    scanf("%f", &speed);

    if (speed > 63)
        puts("Hurricane");
    else if (speed >= 48)
        puts("Storm");
    else if (speed >= 28)
        puts("Gale");
    else if (speed >= 4)
        puts("Breeze");
    else if (speed >= 1)
        puts("Light air");
    else
        puts("Calm");

    return 0;
}
