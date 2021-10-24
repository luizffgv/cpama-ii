#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define LENGTH 64

int  ReadLine(char *dest, int len_max);
bool is_palindrome(const char *message);

int main(void)
{
    char str[LENGTH];
    int  str_len;

    printf("Enter a message: ");
    str_len = ReadLine(str, LENGTH);

    if (is_palindrome(str))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}

int ReadLine(char *dest, int len_max)
{
    char  ch_buf;
    char *ch_cur = dest;
    --len_max;

    while ((ch_buf = getchar()) != '\n' && ch_cur < dest + len_max - 1)
        if (isalpha(ch_buf)) *ch_cur++ = tolower(ch_buf);
    *ch_cur = '\0';

    return ch_cur - dest;
}

bool is_palindrome(const char *message)
{
    const char *end = message;

    while (*end)
        ++end;

    --end;

    while (message < end)
    {
        if (*message++ != *end--)
            return false;
    }

    return true;
}