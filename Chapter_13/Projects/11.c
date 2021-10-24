#include <ctype.h>
#include <stdio.h>

void   read_line(char dest[], int size);
double compute_average_word_length(const char *sentence);

int main(void)
{
    char   sentence[64];
    double length;

    printf("Enter a sentence: ");
    read_line(sentence, 64);
    length = compute_average_word_length(sentence);
    printf("Average word length: %.1lf\n", length);

    return 0;
}

void read_line(char dest[], int size)
{
    char buf;

    while (size-- > 1)
        if ((buf = getchar()) == '\n')
            break;
        else
            *dest++ = buf;
    *dest = '\0';
}

double compute_average_word_length(const char *sentence)
{
    int words   = 0;
    int letters = 0;

    while (*sentence)
    {
        if (isalpha(*sentence))
        {
            ++words;
            do
            {
                ++sentence, ++letters;
            }
            while (isalpha(*sentence));
        }
        else
            ++sentence;
    }

    return (double)letters / words;
}