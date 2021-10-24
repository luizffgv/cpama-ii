#include "stack.h"
#include <stdbool.h>    /* C99 only */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ch;
    int op1, op2;

    printf("Enter an RPN expression: ");
    while (1)
    {
        scanf(" %c", &ch);
        switch(ch)
        {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            push(ch - '0');
            break;
        case '+':   push(pop() + pop());
                    break;
        case '-':   op2 = pop();
                    op1 = pop();
                    push(op1 - op2);
                    break;
        case '*':   op2 = pop();
                    op1 = pop();
                    push(op1 * op2);
                    break;
        case '/':   op2 = pop();
                    op1 = pop();
                    push(op1 / op2);
                    break;
        case '=':   printf("Value of expression: %d\n", pop());
                    make_empty();
                    printf("Enter an RPN expression: ");
                    break;
        default:    exit(EXIT_SUCCESS);
        }
    }
}
