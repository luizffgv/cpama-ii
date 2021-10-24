#include <stdlib.h>
#include "queue.h"

struct queue_type
{
    Item *contents;
    int start;
    int end;
    int size_cur;
    int size;
};

Queue QueueCreate(int size)
{
    Queue queue = malloc(sizeof(*queue));

    queue->contents = malloc(sizeof(Item) * size);
    queue->start = 0;
    queue->end = 0;
    queue->size_cur= 0;
    queue->size = size;

    return queue;
}

void QueueMakeEmpty(Queue queue)
{
    queue->start = 0;
    queue->end = 0;
    queue->size_cur= 0;
}

void QueueDestroy(Queue queue)
{
    free(queue->contents);
    free(queue);
}

bool QueueInsert(Queue queue, Item i)
{
    if (QueueIsFull(queue))
        return false;

    queue->contents[queue->end++] = i;
    queue->end %= queue->size;
    ++queue->size_cur;

    return true;
}

Item QueueRemove(Queue queue)
{
    Item item;

    if (QueueIsEmpty(queue))
        return (Item)0;

    item = queue->contents[queue->start];
    ++queue->start;
    queue->start %= queue->size;
    --queue->size_cur;

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
    return queue->size_cur== 0;
}

bool QueueIsFull(Queue queue)
{
    return queue->size_cur == queue->size;
}