#include "PriorityQueue.h"
#include "UsefulHeap.h"

void PQueueInit(PQueue * ppq, PriorityComp pc)
{
    HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue *ppq)
{
    return HIsEmpty(ppq);
}

void PEnqueue(PQueue*ppq, HData data){
    HInsert(ppq, data);
}

HData PDequeue(PQueue *ppq){
    return HDelete(ppq);
}

