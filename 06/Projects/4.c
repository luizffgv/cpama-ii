#include<stdio.h>

int main(void)
{
    float comission, value;

    while (1)
    {
        printf("Enter value of trade: ");
        scanf("%f", &value);

        if (value == 0)
            break;
        else if (value < 2500.00f)
            comission = 30.00f + .017f * value;
        else if (value < 6250.00f)
            comission = 56.00f + .0066f * value;
        else if (value < 20000.00f)
            comission = 76.00f + .0034f * value;
        else if (value < 50000.00f)
            comission = 100.00f + .0022f * value;
        else if (value < 500000.00f)
            comission = 155.00f + .0011f * value;
        else
            comission = 255.00f + .0009f * value;

        printf("Comission: $%.2f\n\n", comission);
    }

    return 0;
}
