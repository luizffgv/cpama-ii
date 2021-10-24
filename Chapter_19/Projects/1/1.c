#include "stackADT.h"
#include <stdbool.h>    /* C99 only */
#include <stdio.h>
#include <stdlib.h>

char contents[STACK_SIZE];
int top = 0;
bool proper;

int main(void)
{
    Stack stack = create();
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
                push(stack, ch_buf);
            if (blocks[i][1] == ch_buf)
                if (pop(stack) != blocks[i][0])
                    proper = false;
        }
    }
    if (proper && is_empty(stack))
        printf("Parentheses/braces are nested properly\n");
    else
        printf("Parentheses/braces not nested properly\n");

    destroy(stack);
    return 0;
}