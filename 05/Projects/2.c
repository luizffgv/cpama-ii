#include<stdio.h>

int main(void)
{
    int hours, minutes, newhours;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    printf("Equivalent 12-hour time: ");

    if (hours >= 13)
    {
        newhours = hours - 12;
    }
    else newhours = hours;

    printf("%d:%.2d ", newhours, minutes);

    if (hours >= 12)
    {
        printf("PM\n");
    }
    else printf("AM\n");

    return 0;
}
