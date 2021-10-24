#include<stdio.h>
#define PI 3.14159f

int main(void)
{
	float v, radius;

	printf("Enter the radius of the sphere: ");
	scanf("%f", &radius);

	v = 4.0f / 3.0f * PI * radius * radius * radius;

	printf("%f\n", v);

	return 0;
}