#include <stdio.h>

int main(int argc, char *argv[])
{
    for (char **p = argv + argc - 1; p > argv; --p)
        printf("%s ", *p);
    putchar('\n');

    return 0;
}