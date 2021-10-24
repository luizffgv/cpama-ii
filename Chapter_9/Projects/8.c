#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    char selection, buf;

    srand(time(NULL));

    do
    {
        if (play_game())
            printf("You win!\n\n");
        else
            printf("You lose!\n\n");
        printf("Play again? ");

        while ((buf = getchar()) != '\n')
            selection = buf;
    }
    while (toupper(selection) == 'Y');

    return 0;
}

int roll_dice(void)
{
    return rand() % 7 + rand() % 7;
}

bool play_game(void)
{
    int point;
    int roll;
    roll = point = roll_dice();

    printf("You rolled: %d\n", roll);

    if (roll == 7 || roll == 11)
        return true;
    else if (roll == 2 || roll == 3 || roll == 12)
        return false;
    else
    {
        printf("Your point is %d\n", point);

        while (roll != 7)
        {
            roll = roll_dice();
            printf("You rolled: %d\n", roll);

            if (roll == point) return true;
        }
        return false;
    }
}