#include<stdio.h>

int main(void)
{
    float number, number_largest = 0;

    printf("Enter a number: ");
    scanf("%f", &number);

    while (number > 0)
    {
        if (number > number_largest) number_largest = number;

        printf("Enter a number: ");
        scanf("%f", &number);
    }

    printf("The largest number entered was %.2f\n", number_largest);

    return 0;
}
