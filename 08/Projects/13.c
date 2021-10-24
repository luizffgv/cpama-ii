#include<stdio.h>

int main(void)
{
    int i = 0;
    char initial;
    char name_last[21];

    printf("Enter a first and last name: ");

    scanf(" %c", &initial);

    while (getchar() != ' ');

    while ((name_last[i++] = getchar()) != '\n');
    name_last[i-1] = '\0';

    printf("You entered the name: ");
    for(i = 0; name_last[i] != '\0'; i++)
        putchar(name_last[i]);

    printf(", %c.\n", initial);

    return 0;
}
