#include <stdio.h>
#include "PriorityQueue.h"

int DataPriorityComp(char ch1, char ch2)
{
    return ch2 - ch1;
}

int main(void)
{
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);

    PEnqueue(&pq, 'A'); // 굳이 우선순위 정보까지 함께 넘길 필요는 없는데?
    PEnqueue(&pq, 'B');
    PEnqueue(&pq, 'C');
    printf("%c \n", PDequeue(&pq));
    PEnqueue(&pq, 'A');
    PEnqueue(&pq, 'B');
    PEnqueue(&pq, 'C');
    printf("%c \n", PDequeue(&pq));

    while (!PQIsEmpty(&pq))
        printf("%c \n", PDequeue(&pq));

    return 0;
}