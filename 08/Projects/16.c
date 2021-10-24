#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int i;
    char buf;
    int letter_count[26] = {0};

    printf("Enter first word: ");
    while ((buf = getchar()) != '\n')
        if (isalpha(buf))
            ++letter_count[tolower(buf) - 'a'];

    printf("Enter second word: ");
    while ((buf = getchar()) != '\n')
        if (isalpha(buf))
            --letter_count[tolower(buf) - 'a'];

    for (i = 0; (letter_count[i] == 0) && i < 26; i++);
    if (i == 26)
        printf("The words are anagrams");
    else printf("The words are not anagrams");

    return 0;
}
