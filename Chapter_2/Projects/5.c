#include<stdio.h>

int main()
{
	float x, result;

	printf("Enter a value for x: ");
	scanf("%f", &x);

	result = (3 * x * x * x * x * x) + (2 * x * x * x * x) - (5 * x * x * x)
	- (x * x) + (7 * x) - 6;

	printf("The result is %f\n", result);

	return 0;
}