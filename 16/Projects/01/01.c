#include <stdio.h>
#include "country_codes.h"

int main(void)
{
    int country;
    int code;

    for (;;)
    {
        printf("Enter a country code (-1 to exit): ");
        scanf("%d", &code);
        if (code == -1)
            return 0;

        for (country = 0; country < COUNTRIES; ++country)
        {
            if (country_codes[country].code == code)
            {
                printf("Corresponds to %s.\n", country_codes[country].country);
                break;
            }
        }
        if (country == COUNTRIES)
            puts("Country not found.");
    }
}