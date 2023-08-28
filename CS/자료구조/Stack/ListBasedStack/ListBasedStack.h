#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    /* data */
    Data data;
    struct _node * next;
}Node;


typedef struct _listBasedStack
{
    /* data */
    Node* head;
}ListBasedStack;

typedef ListBasedStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif