#include <ctype.h>
#include <stdio.h>

#define LENGTH 128

char read_words(char (*dest)[21]);

int main(void)
{
    int  i;
    char words[30][21] = { "" };
    char last_char     = '\0';

    printf("Enter a sentence: ");
    last_char = read_words(words);

    printf("Reversal of sentence: ");
    for (i = 0; words[i][0]; ++i)
        ;
    for (i -= 1; i > 0; --i)
    {
        printf("%s ", words[i]);
    }
    printf("%s%c\n", words[0], last_char);

    return 0;
}

char read_words(char (*dest)[21])
{
    char buf;
    char last_char = '\0';
    int  words     = 0;
    int  ch;

    do
    {
        while ((buf = getchar()) == ' ') // Skip whitespace
            ;

        ch = 0;
        while ((buf != ' ' && buf != '\n'))
        {
            dest[words][ch] = buf;
            ++ch;
            buf = getchar();
        }
        dest[words++][ch] = '\0';

    } while (buf != '\n');

    if (ispunct(dest[words - 1][ch - 1]))
    {
        last_char               = dest[words - 1][ch - 1];
        dest[words - 1][ch - 1] = '\0';
    }
    return last_char;
}