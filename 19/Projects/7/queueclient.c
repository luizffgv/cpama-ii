#include <stdio.h>
#include "queue.h"

int main(void)
{
    Queue q1, q2;
    int n;

    q1 = QueueCreate();
    q2 = QueueCreate();

    QueueInsert(q1, 1);
    QueueInsert(q1, 2);

    n = QueueRemove(q1);
    printf("Popped %d from q1\n", n);
    QueueInsert(q2, n);
    n = QueueRemove(q1);
    printf("Popped %d from q1\n", n);
    QueueInsert(q2, n);

    QueueDestroy(q1);

    while (!QueueIsEmpty(q2))
        printf("Popped %d from q2\n", QueueRemove(q2));

    QueueInsert(q2, 3);
    QueueMakeEmpty(q2);
    if (QueueIsEmpty(q2))
        printf("q2 is empty\n");
    else
        printf("q2 is not empty\n");

    QueueDestroy(q2);

    return 0;
}