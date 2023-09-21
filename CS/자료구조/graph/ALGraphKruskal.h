#ifndef __AL_GRAPH_KRUSKAL__
#define __AL_GRAPH_KRUSKAL__

#include "DLinkedList.h"
#include "PriorityQueue.h"
#include "ALEdge.h"

enum {A,B,C,D,E,F,G,H,I,J};
typedef struct _ual
{
    /* data */

    int numV;
    int numE;
    List* adjList;
    int* visitInfo;
    PQueue pqueue;
}ALGraph;

void GraphInit(ALGraph* pg, int nv);
void GraphDestroy(ALGraph * pg);

void AddEdge(ALGraph* pg, int fromV, int toV, int weight);

void ShowGraphEdgeInf(ALGraph*pg);
void ConKruskalMST(ALGraph * pg);
void ShowGraphEdgeWeightInfo(ALGraph* pg);

#endif