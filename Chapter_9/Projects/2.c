#include <stdio.h>

float tax(float income);

int main(void)
{
    float income_taxable, income_tax;

    printf("Enter the amount of taxable income: ");
    scanf("%f", &income_taxable);

    income_tax = tax(income_taxable);

    printf("Tax due: $%.3f\n", income_tax);

    return 0;
}

float tax(float income)
{
    float tax;

    if (income <= 750)
        tax = income * 0.01f;
    else if (income <= 2250)
        tax = 7.5f + (income - 750) * 0.02f;
    else if (income <= 3750)
        tax = 37.5f + (income - 2250) * 0.03f;
    else if (income <= 5250)
        tax = 82.5f + (income - 3750) * 0.04f;
    else if (income <= 7000)
        tax = 142.5f + (income - 5250) * 0.05f;
    else
        tax = 230 + (income - 7000) * 0.06f;

    return tax;
}