#include<stdio.h>

int main(void)
{
    int word_count = 1;
    int letter_count = 0;
    char buf;

    printf("Enter a sentence: ");

    while ((buf = getchar()) != '\n')
    {
        if (buf != ' ')
        {
            letter_count++;
        }
        else
        {
            scanf(" ");
            word_count++;
        }
    }

    printf("Average word length: %.1f\n", (float)letter_count / word_count);

    return 0;
}
