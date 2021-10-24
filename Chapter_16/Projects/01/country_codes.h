#ifndef COUNTRY_CODES_H
#define COUNTRY_CODES_H

#define COUNTRIES 32

struct dialing_code {
    char *country;
    int code;
};

extern const struct dialing_code country_codes[];

#endif