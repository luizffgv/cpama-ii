#include <stdio.h>

#define MAX_DIGITS 10

int segments[10][7] = { {1, 1, 1, 0, 1, 1, 1},
                        {0, 0, 1, 0, 0, 1, 0},
                        {1, 0, 1, 1, 1, 0, 1},
                        {1, 0, 1, 1, 0, 1, 1},
                        {0, 1, 1, 1, 0, 1, 0},
                        {1, 1, 0, 1, 0, 1, 1},
                        {1, 1, 0, 1, 1, 1, 1},
                        {1, 0, 1, 0, 0, 1, 0},
                        {1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 0, 1, 1} };

char digits[4][MAX_DIGITS * 4];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
    char buf;
    int digits_read = 0;

    clear_digits_array();

    printf("Enter a number: ");
    while ((buf = getchar()) != '\n' && digits_read < MAX_DIGITS)
    {
        if (buf >= '0' && buf <= '9')
            process_digit(buf - '0', digits_read++ * 4);
    }
    print_digits_array();

    return 0;
}

void clear_digits_array(void)
{
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < MAX_DIGITS * 4; x++)
            digits[y][x] = ' ';
}

void process_digit(int digit, int position)
{
    if (segments[digit][0]) digits[0][position + 1] = '_';
    if (segments[digit][1]) digits[1][position]     = '|';
    if (segments[digit][3]) digits[1][position + 1] = '_';
    if (segments[digit][2]) digits[1][position + 2] = '|';
    if (segments[digit][4]) digits[2][position]     = '|';
    if (segments[digit][6]) digits[2][position + 1] = '_';
    if (segments[digit][5]) digits[2][position + 2] = '|';
}

void print_digits_array(void)
{
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < MAX_DIGITS * 4; x++)
            putchar(digits[y][x]);
        putchar('\n');
    }
}