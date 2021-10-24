#include <stdbool.h>
#include "stack.h"

void StackMakeEmpty(Stack *stack)
{
    stack->top = 0;
}

bool StackIsFull(Stack *stack)
{
    return stack->top == STACK_LEN;
}

bool StackIsEmpty(Stack *stack)
{
    return stack->top == 0;
}

bool StackPush(Stack *stack, Item item)
{
    if (StackIsFull(stack))
        return false;

    stack->contents[stack->top++] = item;

    return true;
}

Item StackPop(Stack *stack)
{
    if (StackIsEmpty(stack))
        return (Item)0;
    return stack->contents[--stack->top];
}