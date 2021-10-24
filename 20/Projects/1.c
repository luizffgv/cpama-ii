#include <stdio.h>

union fp
{
    float float_var;
    struct // C11 unnamed structure
    {
        unsigned fraction : 23;
        unsigned exponent : 8;
        unsigned sign     : 1;
    };
};

int main(void)
{
    union fp fp;

    fp.sign = 1;
    fp.exponent = 128;
    fp.fraction = 0;

    printf("%f\n", fp.float_var);

    return 0;
}