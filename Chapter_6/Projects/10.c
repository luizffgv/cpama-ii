#include<stdio.h>

int main(void)
{
    int monthEarlier, dayEarlier, yearEarlier;
    int date_month, date_day, date_year, swap;

    printf("Enter a date (mm/dd/yy): ");
    scanf("%d /%d /%d", &monthEarlier, &dayEarlier, &yearEarlier);

    do
    {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d /%d /%d", &date_month, &date_day, &date_year);

        if (date_month + date_day + date_year == 0)
            break;

        swap = 0;
        if (date_year != yearEarlier)
        {
            swap = (date_year < yearEarlier);
        }
        else if (date_month != monthEarlier)
        {
            swap = (date_month < monthEarlier);
        }
        else if (date_day != dayEarlier)
        {
            swap = (date_day < dayEarlier);
        }

        if (swap)
        {
            yearEarlier = date_year;
            monthEarlier = date_month;
            dayEarlier = date_day;
        }

    }
    while (date_month + date_day + date_year != 0);

    printf("%d/%d/%.2d is the earliest date\n", monthEarlier, dayEarlier, yearEarlier);
}
