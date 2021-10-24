#include <stdbool.h>    /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
char contents[STACK_SIZE];
int top = 0;
bool proper;

bool is_empty(void);
bool is_full(void);
void stack_overflow(void);
void stack_underflow(void);
void push(char ch);
char pop(void);

int main(void)
{
    char ch_buf;
    char blocks[2][2] = { {'{', '}'},
                          {'(', ')'} };

    proper = true;
    while ((ch_buf = getchar()) != '\n')
    {
        int i;
        for (i = 0; i < 2; i++)
        {
            if (blocks[i][0] == ch_buf)
                push(ch_buf);
            if (blocks[i][1] == ch_buf)
                if (pop() != blocks[i][0])
                    proper = false;
        }
    }
    if (proper && is_empty())
        printf("Parentheses/braces are nested properly\n");
    else
        printf("Parentheses/braces not nested properly\n");

    return 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void stack_overflow(void)
{
    printf("Stack overflow\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
    proper = false;
}

void push(char ch)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = ch;
}

char pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}
