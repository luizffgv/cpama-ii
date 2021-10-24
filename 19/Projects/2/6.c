#include "stackADT.h"
#include <stdbool.h>    /* C99 only */
#include <stdio.h>
#include <stdlib.h>

void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
    Stack stack = create();
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
            push(stack, ch - '0');
            break;
        case '+':   push(stack, pop(stack) + pop(stack));
                    break;
        case '-':   op2 = pop(stack);
                    op1 = pop(stack);
                    push(stack, op1 - op2);
                    break;
        case '*':   op2 = pop(stack);
                    op1 = pop(stack);
                    push(stack, op1 * op2);
                    break;
        case '/':   op2 = pop(stack);
                    op1 = pop(stack);
                    push(stack, op1 / op2);
                    break;
        case '=':   printf("Value of expression: %d\n", pop(stack));
                    make_empty(stack);
                    printf("Enter an RPN expression: ");
                    break;
        default:    exit(EXIT_SUCCESS);
        }
    }

    destroy(stack);

    return 0;
}