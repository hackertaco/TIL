#ifndef __AL_GRAPH__
#define __AL_GRAPH__

#include "DLinkedList.h"

enum {A,B,C,D,E,F,G,H,I,J};

typedef struct _ual
{
    /* data */
    int numV;
    int numE;
    List* adjList;
}ALGraph;

void GraphInit(ALGraph* pg, int nv);
void GraphDestroy(ALGraph* pg);
void AddEdge(ALGraph* pg, int fromV, int toV);
void ShowGraphEdgeInfo(ALGraph* pg);

#endif
