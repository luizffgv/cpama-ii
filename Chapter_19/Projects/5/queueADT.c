#include <stdlib.h>
#include "queue.h"

struct queue_type
{
    Item contents[QUEUE_SIZE];
    int start;
    int end;
    int length;
};

Queue QueueCreate(void)
{
    Queue queue = malloc(sizeof(*queue));

    queue->start = 0;
    queue->end = 0;
    queue->length = 0;

    return queue;
}

void QueueMakeEmpty(Queue queue)
{
    queue->start = 0;
    queue->end = 0;
    queue->length = 0;
}

void QueueDestroy(Queue queue)
{
    free(queue);
}

bool QueueInsert(Queue queue, Item i)
{
    if (QueueIsFull(queue))
        return false;

    queue->contents[queue->end++] = i;
    queue->end %= QUEUE_SIZE;
    ++queue->length;

    return true;
}

Item QueueRemove(Queue queue)
{
    Item item;

    if (QueueIsEmpty(queue))
        return (Item)0;

    item = queue->contents[queue->start];
    ++queue->start;
    queue->start %= QUEUE_SIZE;
    --queue->length;

    return item;
}

Item QueuePeekStart(Queue queue)
{
    return queue->contents[queue->start];
}

Item QueuePeekEnd(Queue queue)
{
    return queue->contents[queue->end - 1];
}

bool QueueIsEmpty(Queue queue)
{
    return queue->length == 0;
}

bool QueueIsFull(Queue queue)
{
    return queue->length == QUEUE_SIZE;
}