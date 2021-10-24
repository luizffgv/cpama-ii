#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


void read_word(int counts[26]);
bool equal_array(int counts[26], int counts2[26]);

int main(void)
{
    int i;
    char buf;
    int letter_count[2][26] = {0};

    printf("Enter first word: ");
    read_word(letter_count[0]);

    printf("Enter second word: ");
    read_word(letter_count[1]);

    if (equal_array(letter_count[0], letter_count[1]))
        printf("The words are anagrams");
    else printf("The words are not anagrams");

    return 0;
}

void read_word(int counts[26])
{
    char buf;

    while ((buf = getchar()) != '\n')
        if (isalpha(buf))
            ++counts[tolower(buf) - 'a'];
}

bool equal_array(int counts1[26], int counts2[26])
{
    int i;
    for (i = 0; i < 26; i++)
        if (counts1[i] != counts2[i])
            break;

    return i == 26 ? true : false;
}