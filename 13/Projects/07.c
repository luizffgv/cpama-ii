#include<stdio.h>

int main(void)
{
    int number_units, number_tens;
    char *tens[] = {"twenty", "thirty", "forty", "fifty", "sixty",
                    "seventy", "eighty", "ninety"};
    char *tens_alt[] = {"ten", "eleven", "twelve", "thirteen", "fourteen",
                        "fifteen", "sixteen", "seventeen", "eighteen",
                        "nineteen"};
    char *units[] = {"-one", "-two", "-three", "-four", "-five", "-six",
                     "-seven", "-eight", "-nine", "-ten"};

    printf("Enter a two-digit number: ");
    scanf("%1d%1d", &number_tens, &number_units);

    printf("You entered the number ");

    if (number_tens != 1)
    {
        printf("%s", tens[number_tens - 2]);
        if (number_units)
            printf("%s", units[number_units - 1]);
    }
    else
        printf("%s", tens_alt[number_units]);
    printf(".\n");

    return 0;
}
