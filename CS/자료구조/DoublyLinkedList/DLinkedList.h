#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node * next;
    struct _node * prev;
}Node;

typedef struct _DLL
{
    Node* head;
    Node* cur;
    int numOfData;
}DList;

typedef DList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data);

int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);
int LPrev(List* plist, Data* pdata);
int LCount(List* plist);

#endif
