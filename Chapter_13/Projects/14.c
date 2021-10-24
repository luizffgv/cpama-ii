#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
    char word1[32], word2[32];

    printf("Enter first word: ");
    scanf("%s", word1);

    printf("Enter second word: ");
    scanf("%s", word2);

    if (are_anagrams(word1, word2))
        puts("The words are anagrams");
    else
        puts("The words are not anagrams");

    return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
    int letter_count[26] = { 0 };

    while (*word1)
    {
        if (isalpha(*word1)) ++letter_count[tolower(*word1) - 'a'];
        ++word1;
    }
    while (*word2)
    {
        if (isalpha(*word2)) --letter_count[tolower(*word2) - 'a'];
        ++word2;
    }

    for (int i = 0; i < 26; i++)
        if (letter_count[i]) return false;
    return true;
}