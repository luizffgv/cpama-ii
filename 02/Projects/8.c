#include<stdio.h>

int main(void)
{
	float amount, interest, payment;

	printf("Enter amount of loan: ");
	scanf("%f", &amount);
	printf("Enter interest of loan: ");
	scanf("%f", &interest);
	printf("Enter monthly payment: ");
	scanf("%f", &payment);

	interest = (interest / 100) / 12;

	amount = amount - payment + (amount * interest);
	printf("Balance remaining after first payment: $%.2f\n", amount);
	amount = amount - payment + (amount * interest);
	printf("Balance remaining after second payment: $%.2f\n", amount);
	amount = amount - payment + (amount * interest);
	printf("Balance remaining after third payment: $%.2f\n", amount);

	return 0;
}