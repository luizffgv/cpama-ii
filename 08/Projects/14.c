#include <stdio.h>

#define LENGTH 128

int main(void)
{
    int i, j;
    char sentence[128] = {'\0'};
    char last_char = '\0';
    char buf;

    printf("Enter a sentence: ");

    i = -1;
    while ((buf = getchar()) != '\n')
    {
        if (buf == '!' || buf == '.' || buf == '?')
        {
            last_char = buf;
            break;
        }
        else sentence[++i] = buf;
    }

    printf("Reversal of sentence: ");
    for (; i >= 0; i--)
    {
        if (i == 0 || sentence[i-1] == ' ')
        {
            for (j = i; sentence[j] != ' ' && sentence[j] != '\0'; j++)
                putchar(sentence[j]);
            if (i == 0) putchar(last_char);
            else putchar(' ');
        }
    }

    return 0;
}
