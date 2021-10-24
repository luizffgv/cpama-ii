#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define QUEUE_SIZE 10

struct queue
{
    Item items[QUEUE_SIZE];
    int end;
    int start;
    int items_num;
};

Queue QueueCreate(void)
{
    Queue queue_new = calloc(1, sizeof(*queue_new));

    return queue_new;
}

void QueueDestroy(Queue queue)
{
    free(queue);
}

bool QueueInsert(Queue queue, Item i)
{
    if (QueueIsFull(queue))
        return false;

    queue->items[queue->end] = i;
    ++queue->items_num;
    if (++queue->end == QUEUE_SIZE)
        queue->end = 0;

    return true;
}

Item QueueRemove(Queue queue)
{
    int item;

    if (QueueIsEmpty(queue))
    {
        puts("Queue is already empty.\n"
             "ENTER to continue...");
        getchar();
        return 0;
    }

    item = queue->items[queue->start];
    ++queue->start;
    --queue->items_num;
    if (queue->start == QUEUE_SIZE)
        queue->start = 0;
    
    return item;
}

Item QueuePeekStart(Queue queue)
{
    return queue->items[queue->start];
}

Item QueuePeekEnd(Queue queue)
{
    return queue->items[queue->end];
}

bool QueueIsEmpty(Queue queue)
{
    return queue->items_num == 0;
}

bool QueueIsFull(Queue queue)
{
    return queue->items_num == QUEUE_SIZE;
}