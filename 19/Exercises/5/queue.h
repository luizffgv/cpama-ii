#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int Item;

typedef struct queue Queue;

bool QueueInsert(Queue *queue, Item i);
Item QueueRemove(Queue *queue);
Item QueuePeekStart(Queue *queue);
Item QueuePeekEnd(Queue *queue);
bool QueueIsEmpty(Queue *queue);

#endif