#include<stdio.h>

int main(void)
{
    int i;
    int hours, minutes, aftermidnight_minutes;
    int closest_index, closest_difference, difference;
    int departure_times[7] = {480, 679, 767, 840, 945, 1140, 1305};
    int arrival_times[7] = {616, 811, 900, 968, 1075, 1280, 1438};

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hours, &minutes);

    aftermidnight_minutes = minutes + hours * 60;

    closest_difference = aftermidnight_minutes - departure_times[0];
    closest_index = 0;
    if (closest_difference < 0)
        closest_difference = -closest_difference;

    for (i = 1; i < 7; i++)
    {
        difference = aftermidnight_minutes - departure_times[i];
        if (difference < 0)
            difference = -closest_difference;
        if (difference < closest_difference)
        {
            closest_difference = difference;
            closest_index = i;
        }
    }

    minutes = departure_times[closest_index] % 60;
    hours = departure_times[closest_index] / 60;
    if (hours > 12)
    {
        hours -= 12;
        printf("Closest departure time is %d:%d p.m., ", hours, minutes);
    }
    else printf("Closest departure time is %d:%d a.m., ", hours, minutes);


    minutes = arrival_times[closest_index] % 60;
    hours = arrival_times[closest_index] / 60;
    if (hours > 12)
    {
        hours -= 12;
        printf("Arriving at %d:%d p.m.\n", hours, minutes);
    }
    else printf("Arriving at %d:%d a.m.\n", hours, minutes);

    return 0;
}
