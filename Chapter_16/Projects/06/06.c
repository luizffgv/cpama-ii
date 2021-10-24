#include "dates.h"
#include<stdio.h>

int main(void)
{
    struct date dates[2];
    int earlier;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d /%d /%d", &dates[0].month, &dates[0].day, &dates[0].year);
    printf("Enter first date (mm/dd/yy): ");
    scanf("%d /%d /%d", &dates[1].month, &dates[1].day, &dates[1].year);

    earlier = compare_dates(dates[0], dates[1]);

    switch (earlier) 
    {
    case -1:
        printf("%d/%d/%d is earlier than %d/%d/%d\n",
            dates[0].month, dates[0].day, dates[0].year, dates[1].month,
            dates[1].day, dates[1].year);
        break;
    case 1:
        printf("%d/%d/%d is earlier than %d/%d/%d\n",
            dates[1].month, dates[1].day, dates[1].year, dates[0].month,
            dates[0].day, dates[0].year);
        break;
    case 0:
        printf("The dates are equal.\n");
        break;
    }

    return 0;
}
