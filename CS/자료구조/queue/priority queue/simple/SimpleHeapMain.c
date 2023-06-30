#include <stdio.h>
#include "SimpleHeap.h"

int main(void)
{
    Heap heap;
    HeapInit(&heap);

    HInsert(&heap, 'A', 1); // 굳이 우선순위 정보까지 함께 넘길 필요는 없는데? 
    HInsert(&heap, 'B', 2);
    HInsert(&heap, 'C', 3);
    printf("%c \n", HDelete(&heap));
    HInsert(&heap, 'A', 1);
    HInsert(&heap, 'B', 2);
    HInsert(&heap, 'C', 3);
    printf("%c \n", HDelete(&heap));

    while(!HIsEmpty(&heap))
        printf("%c \n", HDelete(&heap));

    return 0;

}