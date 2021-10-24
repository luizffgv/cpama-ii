#include<stdio.h>
#define PI 3.14159f
#define RADIUS 10

int main(void)
{
	float v;
	v = 4.0f / 3.0f * PI * RADIUS * RADIUS * RADIUS;

	printf("%f\n", v);

	return 0;
}