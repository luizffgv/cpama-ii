#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef int Item;

typedef struct stack *Stack;

void StackDestroy(Stack stack);
Stack StackCreate(void);
void StackMakeEmpty(Stack stack);
bool StackIsEmpty(Stack stack);
bool StackPush(Stack stack, Item i);
Item StackPop(Stack stack);

#endif