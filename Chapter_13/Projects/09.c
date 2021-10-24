#include <ctype.h>
#include <stdio.h>

void read_line(char *dest, int size);
int  compute_vowel_count(const char *sentence);

int main(void)
{
    char str[64];
    int  vowel_count;

    read_line(str, 64);
    vowel_count = compute_vowel_count(str);

    printf("Your sentence contains %d vowels.\n", vowel_count);

    return 0;
}

void read_line(char *dest, int size)
{
    char buf;
    int  i = 0;

    while (i < size - 1)
        if ((buf = getchar()) == '\n')
            break;
        else
            dest[i++] = buf;
    dest[i] = '\0';
}

int compute_vowel_count(const char *sentence)
{
    int count = 0;

    while (*sentence != '\0')
        switch (toupper(*sentence++))
        {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U': ++count; break;
        }

    return count;
}