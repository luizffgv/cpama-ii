#include<stdio.h>

int main()
{
	float x, result;

	printf("Enter a value for x: ");
	scanf("%f", &x);

	result = (((( 3 * x + 2 )* x - 5 )* x - 1 )* x + 7) * x - 6;

	printf("The result is %f\n", result);

	return 0;
}