#include<stdio.h>
#include<ctype.h>

int main(void)
{
    int hours, minutes;
    char indicator;

    printf("Enter a 12-hour time: ");
    scanf("%d :%d %c", &hours, &minutes, &indicator);

    if (toupper(indicator) == 'P') hours += 12;

    printf("Equivalent 24-hour time: %d:%d\n", hours, minutes);

    return 0;
}
