#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"


struct queue_node
{
    Item item;
    struct queue_node *next;
};

struct queue_type
{
    struct queue_node *first;
    struct queue_node *last;
};

Queue QueueCreate(void)
{
    Queue queue_new  = malloc(sizeof(*queue_new));   
    queue_new->first = NULL;
    queue_new->last  = NULL;
    return queue_new;
}

void QueueMakeEmpty(Queue queue)
{
    for (struct queue_node *prev = NULL, *node = queue->first;
         node != NULL;
         prev = node, node = node->next)
        free(prev);
    queue->first = NULL;
    queue->last  = NULL;
}

void QueueDestroy(Queue queue)
{
    QueueMakeEmpty(queue);
    free(queue);
}

bool QueueInsert(Queue queue, Item i)
{
    struct queue_node *node_new = malloc(sizeof(*node_new));
    if (node_new == NULL)
        return false;
    
    node_new->item = i;
    node_new->next = NULL;

    if (QueueIsEmpty(queue))
    {
        queue->first = node_new;
        queue->last  = node_new;
    }
    else
    {
        queue->last->next = node_new;
        queue->last       = node_new;
    }

    return true;
}

Item QueueRemove(Queue queue)
{
    if (!QueueIsEmpty(queue))
    {
        struct queue_node *node_temp;
        Item item;

        item = queue->first->item;
        node_temp = queue->first;
        queue->first = queue->first->next;
        if (queue->first == NULL)
            queue->last = NULL;
        free(node_temp);

        return item;
    }
    else
        return (Item)0;

}

Item QueuePeekStart(Queue queue)
{
    if (!QueueIsEmpty(queue))
        return queue->first->item;
    else
        return (Item)0;
}

Item QueuePeekEnd(Queue queue)
{
    if (!QueueIsEmpty(queue))
        return queue->last->item;
    else
        return (Item)0;
}

bool QueueIsEmpty(Queue queue)
{
    return queue->first == NULL;
}

bool QueueIsFull(Queue queue)
{
    return false;
}