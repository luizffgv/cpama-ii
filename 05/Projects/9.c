#include<stdio.h>

int main(void)
{
    int earlier = 0;
    int date1_day, date1_month, date1_year;
    int date2_day, date2_month, date2_year;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d /%d /%d", &date1_month, &date1_day, &date1_year);
    printf("Enter first date (mm/dd/yy): ");
    scanf("%d /%d /%d", &date2_month, &date2_day, &date2_year);

    if (date1_year != date2_year)
    {
        earlier = date1_year < date2_year ? 1 : 2;
    }
    else if (date1_month != date2_month)
    {
        earlier = date1_month < date2_month ? 1 : 2;
    }
    else if (date1_day != date2_day)
    {
        earlier = date1_day < date2_day ? 1 : 2;
    }

    if (earlier)
    {
        if (earlier == 1)
        {
            printf("%d/%d/%d is earlier than %d/%d/%d\n",
                date1_month, date1_day, date1_year, date2_month, date2_day, date2_year);
        }
        else
        {
            printf("%d/%d/%d is earlier than %d/%d/%d\n",
                date2_month, date2_day, date2_year, date1_month, date1_day, date1_year);
        }
    }
    else printf("The dates are equal.\n");

    return 0;
}
