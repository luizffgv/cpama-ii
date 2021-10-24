#include "queue.h"
#include <stdio.h>

int main(void)
{
    Queue queue = QueueCreate();

    QueueInsert(queue, 1);
    QueueInsert(queue, 3);
    QueueInsert(queue, 5);
    QueueInsert(queue, 7);
    QueueRemove(queue);
    QueueRemove(queue);
    QueueRemove(queue);
    QueueRemove(queue);
    QueueInsert(queue, 1);
    QueueInsert(queue, 3);
    QueueInsert(queue, 5);
    QueueInsert(queue, 7);
    QueueInsert(queue, 1);
    QueueRemove(queue);
    QueueRemove(queue);
    QueueRemove(queue);
    QueueRemove(queue);
    QueueInsert(queue, 3);
    QueueInsert(queue, 5);
    QueueInsert(queue, 7);
    QueueInsert(queue, 1);
    QueueInsert(queue, 3);
    QueueRemove(queue);
    QueueRemove(queue);
    QueueRemove(queue);
    QueueRemove(queue);
    QueueInsert(queue, 5);
    QueueInsert(queue, 7);

    printf("%d\n", QueueRemove(queue));
    printf("%d\n", QueueRemove(queue));
    printf("%d\n", QueueRemove(queue));
    printf("%d\n", QueueRemove(queue));

    QueueDestroy(queue);

    return 0;
}