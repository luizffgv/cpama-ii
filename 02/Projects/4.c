#include<stdio.h>

#define TAX 5.0f

int main(void)
{
	float amount;

	printf("Enter an amount: ");
	scanf("%f", &amount);

	printf("With tax added: $%.2f\n", amount + amount * TAX / 100);

	return 0;
}