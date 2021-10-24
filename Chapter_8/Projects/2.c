/* Checks numbers for repeated digits */

#include<stdio.h>

int main(void)
{
    int digit_count[10] = {0};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        ++digit_count[digit];
        n /= 10;
    }

    printf("Digit:     ");
    for (int i = 0; i < 10; i++)
        printf("%3d", i);
    printf("\n");
    printf("Occurences:");
    for (int i = 0; i < 10; i++)
        printf("%3d", digit_count[i]);
    printf("\n");

    return 0;
}
