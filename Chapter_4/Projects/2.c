#include<stdio.h>

int main(void)
{
	int number, units, tens, hundreds, reversal;

	printf("Enter a three-digit number: ");
	scanf("%d", &number);

	hundreds = number / 100;
	number %= 100;
	tens = number / 10 * 10;
	number %= 10;
	units = number * 100;

	reversal = units + tens + hundreds;

	printf("The reversal is: %.3d\n", reversal);

	return 0;
}