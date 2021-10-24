#include <stdio.h>

#define SIZE 64

int  ReadLine(char *str, int size);
void reverse(char *message);

int main(void)
{
    char str[SIZE];
    int  str_length;

    printf("Enter a message: ");
    str_length = ReadLine(str, SIZE - 1);
    str[str_length + 1] = '\0';

    reverse(str);
    printf("Reversal is: ");
    puts(str);

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

void reverse(char *message)
{
    char *end = message;
    char temp;

    while (*end)
        ++end;

    while (message < --end)
    {
        temp = *end;
        *end = *message;
        *message = temp;
        ++message;
    }
}