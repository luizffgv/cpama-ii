#include<stdio.h>

int main(void)
{
    float rival_comission, broker_comission, value, shares_price, shares_number;

    printf("Enter number of shares: ");
    scanf("%f", &shares_number);
    printf("Enter price per share: ");
    scanf("%f", &shares_price);

    value = shares_number * shares_price;

    if (value < 2500.00f)
        broker_comission = 30.00f + .017f * value;
    else if (value < 6250.00f)
        broker_comission = 56.00f + .0066f * value;
    else if (value < 20000.00f)
        broker_comission = 76.00f + .0034f * value;
    else if (value < 50000.00f)
        broker_comission = 100.00f + .0022f * value;
    else if (value < 500000.00f)
        broker_comission = 155.00f + .0011f * value;
    else
        broker_comission = 255.00f + .0009f * value;

    if (broker_comission < 39.00f)
        broker_comission = 39.00f;

    rival_comission = 33;
    if (shares_number < 2000)
        rival_comission += .03f * shares_number;
    else rival_comission += .02f * shares_number;

    printf("Broker comission: $%.2f\n", broker_comission);
    printf("Rival comission: $%.2f\n", rival_comission);

    return 0;
}
