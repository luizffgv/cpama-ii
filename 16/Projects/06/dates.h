#ifndef DATES_H
#define DATES_H

struct date
{
    int day;
    int month;
    int year;
};

int compare_dates(struct date d1, struct date d2);

#endif