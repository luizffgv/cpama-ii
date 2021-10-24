#include<stdio.h>

int main(void)
{
    int num, numTemp, reversal = 0, factor;

    printf("Enter a number: ");
    scanf("%d", &num);

    numTemp = num;
    factor = 1;
    do
    {
        numTemp /= 10;
        factor *= 10;
    }
    while (numTemp / 10 != 0);

    do
    {
        reversal += num % 10 * factor;

        num /= 10;
        factor /= 10;
    }
    while (num != 0);

    printf("The reversal is: %d\n", reversal);

    return 0;
}
