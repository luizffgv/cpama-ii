#include<stdio.h>

int main(void)
{
    char initial;
    char name_last_char;

    scanf(" %c", &initial);

    while (getchar() != ' ');

    while ((name_last_char = getchar()) != '\n')
    {
        if (name_last_char != ' ')
            printf("%c", name_last_char);
    }

    printf(", %c.\n", initial);

    return 0;
}
