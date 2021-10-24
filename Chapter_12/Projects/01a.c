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
    for (int i = str_length; i >= 0; i--)
        putchar(str[i]);
    putchar('\n');

    return 0;
}

int ReadLine(char *str, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        char ch_buf;
        if ((ch_buf = getchar()) != '\n')
            str[i] = ch_buf;
        else
            break;
    }
    return i - 1;
}