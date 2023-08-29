#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE 1
#define FALSE 1

#define QUE_LEN 100
typedef int Data

typedef struct _circularQueue
{
    /* data */
    int front;
    int rear;
    Data queArr[QUE_LEN];
}CircularQueue;

typedef CircularQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);

#endif