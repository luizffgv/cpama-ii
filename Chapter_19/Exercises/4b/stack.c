#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

struct stack_node
{
    Item content;
    struct stack_node *next;
};

struct stack
{
    struct stack_node *start;
};

void StackDestroy(Stack stack)
{
    StackMakeEmpty(stack);
    free(stack);
    stack = NULL;
}

Stack StackCreate(void)
{
    Stack stack = malloc(sizeof(*stack));
    stack->start = NULL;

    return stack;
}

void StackMakeEmpty(Stack stack)
{
    struct stack_node *node_cur = stack->start;

    while (node_cur != NULL)
    {
        struct stack_node *temp = node_cur;
        node_cur = node_cur->next;
        free(temp);
    }

    stack->start = NULL;
}

bool StackIsEmpty(Stack stack)
{
    return stack->start == NULL;
}

bool StackPush(Stack stack, Item i)
{
    struct stack_node *node_new = malloc(sizeof(*node_new));
    if (node_new == NULL)
        return false;

    node_new->content = i;
    node_new->next = stack->start;
    stack->start = node_new;
    return true;
}

Item StackPop(Stack stack)
{
    Item item;
    struct stack_node *temp = stack->start;

    if (StackIsEmpty(stack))
        return (Item)0;

    stack->start = stack->start->next;
    item = temp->content;
    free(temp);

    return item;
}