#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define LENGTH 64

int ReadLine(char *dest, int len_max);
bool IsPalindrome(char *str, int len);

int main(void)
{
    char str[LENGTH];
    int str_len;

    printf("Enter a message: ");
    str_len = ReadLine(str, LENGTH);

    if (IsPalindrome(str, str_len))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}

int ReadLine(char *dest, int len_max)
{
    char ch_buf;
    int ch_cur = 0;
    --len_max;

    while ((ch_buf = getchar()) != '\n' && ch_cur < len_max)
        if (isalpha(ch_buf))
            dest[ch_cur++] = tolower(ch_buf);
    dest[ch_cur + 1] = '\0';

    return ch_cur;
}

bool IsPalindrome(char *str, int len)
{
    int bot, top;
    bot = 0;
    top = len - 1;

    while (bot < top)
        if (str[bot++] != str[top--])
            return false;

    return true;
}