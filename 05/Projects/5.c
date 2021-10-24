#include<stdio.h>

int main(void)
{
    float income_taxable, income_tax;

    printf("Enter the amount of taxable income: ");
    scanf("%f", &income_taxable);

    if (income_taxable <= 750)
    {
        income_tax = income_taxable * 0.01f;
    }
    else if (income_taxable <= 2250)
    {
        income_tax = 7.5f + (income_taxable - 750) * 0.02f;
    }
    else if (income_taxable <= 3750)
    {
        income_tax = 37.5f + (income_taxable - 2250) * 0.03f;
    }
    else if (income_taxable <= 5250)
    {
        income_tax = 82.5f + (income_taxable - 3750) * 0.04f;
    }
    else if (income_taxable <= 7000)
    {
        income_tax = 142.5f + (income_taxable - 5250) * 0.05f;
    }
    else
    {
        income_tax = 230 + (income_taxable - 7000) * 0.06f;
    }

    printf("Tax due: $%.2f\n", income_tax);

    return 0;
}
