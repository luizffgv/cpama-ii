#include<stdio.h>

int main(void)
{
    int i1, i2, i3, i4, largest, smallest, largest1, smallest1;

    printf("Enter four integers: ");
    scanf("%d%d%d%d", &i1, &i2, &i3, &i4);

    largest = i1;
    smallest = i4;

    if (i3 > i4)
    {
        largest1 = i3;
        smallest1 = i4;
    }
    else
    {
        largest1 = i4;
        smallest1 = i3;
    }

    if (i1 > i2)
    {
        largest = i1;
        smallest = i2;
    }
    else
    {
        largest = i2;
        smallest = i1;
    }

    if (smallest > smallest1) smallest = smallest1;
    if (largest < largest1) largest = largest1;

    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);

    return 0;
}
