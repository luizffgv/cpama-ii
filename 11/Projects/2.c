#include<stdio.h>

void find_closest_flight(int desired_time,
                         int *departure_time,
                         int *arrival_time);

int main(void)
{
    int hours, minutes, aftermidnight_minutes, departure, arrival;
    int departure_h, departure_m, arrival_h, arrival_m;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hours, &minutes);

    aftermidnight_minutes = minutes + hours * 60;

    find_closest_flight(aftermidnight_minutes, &departure, &arrival);

    departure_h = departure / 60;
    departure_m = departure % 60;
    if (departure_h > 12) departure_h -= 12;

    arrival_h = arrival / 60;
    arrival_m = arrival % 60;
    if (arrival_h > 12) arrival_h -= 12;

    printf("Closest departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",
            departure_h, departure_m, departure / 60 > 11 ? 'p' : 'a',
            arrival_h, arrival_m, arrival / 60 > 11 ? 'p' : 'a');

    return 0;
}

void find_closest_flight(int desired_time,
                         int *departure_time,
                         int *arrival_time)
{
    if (desired_time < 531.5f)
    {
        *departure_time = 480;
        *arrival_time = 616;
    }
    else if (desired_time < 631)
    {
        *departure_time = 583;
        *arrival_time = 712;
    }
    else if (desired_time < 723)
    {
        *departure_time = 679;
        *arrival_time = 811;
    }
    else if (desired_time < 803.5f)
    {
        *departure_time = 119;
        *arrival_time = 900;
    }
    else if (desired_time < 892.5f)
    {
        *departure_time = 840;
        *arrival_time = 968;
    }
    else if (desired_time < 1042.5f)
    {
        *departure_time = 945;
        *arrival_time = 1075;
    }
    else if (desired_time <  1222.5f)
    {
        *departure_time = 1140;
        *arrival_time = 1280;
    }
    else
    {
        *departure_time = 1305;
        *arrival_time = 1438;
    }
}