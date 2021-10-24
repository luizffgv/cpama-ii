#include "queue.h"
#include <stdio.h>

int main(void)
{
    Queue queue = QueueCreate();

    QueueInsert(queue, 1);
    QueueRemove(queue);
    QueueInsert(queue, 1);
    QueueInsert(queue, 2);
    QueueRemove(queue);
    QueueRemove(queue);
    QueueInsert(queue, 1);
    QueueInsert(queue, 2);
    QueueInsert(queue, 3);
    QueueInsert(queue, 4);

    printf("%d\n", QueueRemove(queue));
    printf("%d\n", QueueRemove(queue));
    printf("%d\n", QueueRemove(queue));
    printf("%d\n", QueueRemove(queue));

    QueueDestroy(queue);

    return 0;
}