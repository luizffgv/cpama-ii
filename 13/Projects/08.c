#include <ctype.h>
#include <stdio.h>

void read_line(char *target, int size);
int compute_scrabble_value(const char *word);

int main(void)
{
    char word[32];
    int value;

    printf("Enter a word: ");
    read_line(word, 32);
    value = compute_scrabble_value(word);
    printf("Scrabble value: %d\n", value);

    return 0;
}

void read_line(char *target, int size)
{
    char *end = target + size - 1;

    while (target < end)
    {
        if ((*target = getchar()) == '\n')
            break;
        ++target;
    }
    *target = '\0';
}

int compute_scrabble_value(const char *word)
{
    int value = 0;
    // Could use an array instead
    while (*word)
    {
        switch (toupper(*word++))
        {
        case 'D': case 'G':
            value += 2;
            break;
        case 'B': case 'C': case 'M': case 'P':
            value += 3;
            break;
        case 'F': case 'H': case 'V': case 'W': case 'Y':
            value += 4;
            break;
        case 'K':
            value += 5;
            break;
        case 'J': case 'X':
            value += 8;
            break;
        case 'Q': case 'Z':
            value += 10;
            break;
        default:
            ++value;
            break;
        }
    }

    return value;
}
