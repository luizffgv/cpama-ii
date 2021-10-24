#include <stdbool.h>    /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

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

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(int i)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = i;
}

int pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}

void stack_overflow(void)
{
    printf("Expression is too complex\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
    printf("Not enough operands in expression\n");
    exit(EXIT_FAILURE);
}