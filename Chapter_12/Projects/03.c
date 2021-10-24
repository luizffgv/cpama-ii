#include <stdio.h>

#define SIZE 64

int ReadLine(char *str, int size);

int main(void)
{
    char str[SIZE];
    int str_length;

    printf("Enter a message: ");
    str_length = ReadLine(str, SIZE);

    printf("Reversal is: ");
    for (char *p = str + str_length; p >= str; p--)
        putchar(*p);
    putchar('\n');

    return 0;
}

int ReadLine(char *str, int size)
{
    char *p;
    for (p = str; p < str + size; p++)
    {
        char ch_buf;
        if ((ch_buf = getchar()) != '\n')
            *p = ch_buf;
        else
            break;
    }
    return p - str - 1;
}