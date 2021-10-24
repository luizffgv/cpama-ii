#include <stdio.h>
#include <string.h>

int main(void)
{
    char largest[21], smallest[21];
    char word[21];

    printf("Enter word: ");
    scanf("%20s", word);
    strcpy(smallest, strcpy(largest, word));

    while (strlen(word) != 4)
    {
        printf("Enter word: ");
        scanf("%s", word);
        if (strlen(word) == 4)
            break;
        else if (strcmp(word, largest) > 0)
            strcpy(largest, word);
        else if (strcmp(word, smallest) < 0)
            strcpy(smallest, word);
    }

    printf("\nSmallest word: %s\n"
           "Largest word: %s\n", smallest, largest);

    return 0;
}