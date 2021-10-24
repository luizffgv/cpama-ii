#include<stdio.h>
#include<ctype.h>

int main(void)
{
    char ch;
    int vowel_count = 0;

    while ((ch = toupper(getchar())) != '\n')
    {
        switch (ch)
        {
            case 'A': case 'E': case 'I': case 'O': case 'U':
                vowel_count++;
                break;
        }
    }

    printf("Your sentence contains %d vowels.\n", vowel_count);

    return 0;
}
