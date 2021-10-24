#include<stdio.h>

int main(void)
{
    int hours, minutes, aftermidnight_minutes;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hours, &minutes);

    aftermidnight_minutes = minutes + hours * 60;

    if (aftermidnight_minutes < 531.5f)
    {
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    }
    else if (aftermidnight_minutes < 631)
    {
        printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    }
    else if (aftermidnight_minutes < 723)
    {
        printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
    }
    else if (aftermidnight_minutes < 803.5f)
    {
        printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
    }
    else if (aftermidnight_minutes < 892.5f)
    {
        printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    }
    else if (aftermidnight_minutes < 1042.5f)
    {
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    }
    else if (aftermidnight_minutes <  1222.5f)
    {
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    }
    else printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");

    return 0;
}
