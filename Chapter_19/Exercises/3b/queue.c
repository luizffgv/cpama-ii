#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

struct queue_node
{
    Item item;
    struct queue_node *next;
};

struct queue
{
    struct queue_node *first;
    struct queue_node *last;
};

Queue QueueCreate(void)
{
    Queue queue_new = malloc(sizeof(*queue_new));
    queue_new->first = NULL;
    queue_new->last = NULL;

    return queue_new;
}

void QueueDestroy(Queue queue)
{
    struct queue_node *node_cur = queue->first;

    while (node_cur != NULL)
    {
        struct queue_node *temp = node_cur;
        node_cur = node_cur->next;
        free(temp);
    }

    free(queue);
    queue = NULL;
}

bool QueueInsert(Queue queue, Item i)
{
    struct queue_node *node_new = malloc(sizeof(*node_new));
    if (node_new == NULL)
        return false;

    node_new->item = i;
    node_new->next = NULL;

    if (QueueIsEmpty(queue))
        queue->first = node_new;
    else
        queue->last->next = node_new;
    queue->last = node_new;

    return true;
}

Item QueueRemove(Queue queue)
{
    if (!QueueIsEmpty(queue))
    {
        Item item;
        struct queue_node *temp = queue->first;

        queue->first = queue->first->next;
        item = temp->item;

        if (queue->last == temp)
            queue->last = queue->first;

        free(temp);
        
        return item;
    }
    return 0;
}

Item QueuePeekStart(Queue queue)
{
    return queue->first->item;
}

Item QueuePeekEnd(Queue queue)
{
    return queue->last->item;
}

bool QueueIsEmpty(Queue queue)
{
    return queue->first == NULL;
}