#include <stdio.h>

#define LENGTH 128

int main(void)
{
    char *i, *j;
    char sentence[128] = {'\0'};
    char last_char = '\0';
    char buf;

    printf("Enter a sentence: ");

    i = sentence;
    while ((buf = getchar()) != '\n')
    {
        if (buf == '!' || buf == '.' || buf == '?')
        {
            last_char = buf;
            break;
        }
        else
            *i++ = buf;
    }

    printf("Reversal of sentence: ");
    for (--i; i >= sentence; --i)
    {
        if (i == sentence || *(i - 1) == ' ')
        {
            for (j = i; *j != ' ' && *j != '\0'; j++)
                putchar(*j);
            if (i == sentence)
                putchar(last_char);
            else
                putchar(' ');
        }
    }

    return 0;
}
