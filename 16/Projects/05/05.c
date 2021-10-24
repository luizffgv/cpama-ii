#include<stdio.h>

#define FLIGHTS 8

struct flight
{
    int departure;
    int arrival;
};

int abs(int n);

int main(void)
{
    struct flight flights[FLIGHTS] = { {480, 616},   {583, 712},  {679, 811},
                                       {767, 900},   {840, 968},  {945, 1075},
                                       {1140, 1280}, {1305, 1438} };
    int hours, minutes, aftermidnight_minutes;
    int flight_i;
    struct flight closest = flights[0];

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hours, &minutes);

    aftermidnight_minutes = minutes + hours * 60;

    for (flight_i = 1; flight_i < FLIGHTS; ++flight_i)
        if (abs(aftermidnight_minutes - flights[flight_i].departure)
            < abs(aftermidnight_minutes - closest.departure))
            closest = flights[flight_i];

    hours = closest.departure / 60;
    minutes = closest.departure % 60;
    if (hours > 12)
        printf("Closest departure time is %d:%.2d p.m., ", hours, minutes);
    else
        printf("Closest departure time is %d:%.2d a.m., ", hours, minutes);

    hours = closest.arrival/ 60;
    minutes = closest.arrival % 60;
    if (hours > 12)
        printf("arriving at %d:%.2d p.m.\n", hours, minutes);
    else
        printf("arriving at %d:%.2d p.m.\n", hours, minutes);

    return 0;
}

int abs(int n)
{
    return n < 0 ? -n : n;
}