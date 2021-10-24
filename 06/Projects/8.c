#include<stdio.h>

int main(void)
{
    int month_days, week_day;

    printf("Enter number of days in month: ");
    scanf("%d", &month_days);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &week_day);

    for (int i = 1; i < week_day; i++)
    {
        printf("   ");
    }

    for (int i = 1; i <= month_days; i++)
    {
        printf("%2d ", i);
        if ((i + week_day - 1) % 7 == 0)
            printf("\n");
    }
    printf("\n");

    return 0;
}
