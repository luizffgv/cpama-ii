#include<stdio.h>

int main(void)
{
    float amount, interest, payment;
    int months;

    printf("Enter amount of loan: ");
    scanf("%f", &amount);
    printf("Enter interest of loan: ");
    scanf("%f", &interest);
    printf("Enter monthly payment: ");
    scanf("%f", &payment);
    printf("Enter number of payments: ");
    scanf("%d", &months);

    interest = (interest / 100) / 12;

    for (int i = 1; i <= months; i++)
    {
        amount = amount - payment + (amount * interest);
        printf("Balance remanining after payment %d: $%.2f\n", i, amount);
    }

    return 0;
}
