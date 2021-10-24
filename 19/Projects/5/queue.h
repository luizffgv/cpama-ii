#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define QUEUE_SIZE 10

typedef int Item;

typedef struct queue_type *Queue;

Queue QueueCreate(void);
void QueueMakeEmpty(Queue queue);
void QueueDestroy(Queue queue);
bool QueueInsert(Queue queue, Item i);
Item QueueRemove(Queue queue);
Item QueuePeekStart(Queue queue);
Item QueuePeekEnd(Queue queue);
bool QueueIsEmpty(Queue queue);
bool QueueIsFull(Queue queue);

#endif