#include<stdio.h>

int main(void)
{
	int number1, number2, number3;

	printf("Enter a three-digit number: ");
	scanf("%1d%1d%1d", &number1, &number2, &number3);

	printf("The reversal is: %d%d%d\n", number3, number2, number1);

	return 0;
}