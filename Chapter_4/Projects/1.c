#include<stdio.h>

int main(void)
{
	int number, units, tens, reversal;

	printf("Enter a two-digit number: ");
	scanf("%d", &number);

	units = number % 10 * 10;
	tens = number / 10;

	reversal = tens + units;

	printf("The reversal is: %.2d\n", reversal);

	return 0;
}