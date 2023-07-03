#include <stdio.h>
#include "UsefulHeap.h"

int Pricomp(int n1, int n2)
{
    return n2 - n1;
}
void HeapSort(int arr[], int n, PriorityComp pc)
{
    Heap heap;
    int i;
    HeapInit(&heap, pc);

    for(i=0; i<n; i++)
        HInsert(&heap, arr[i]); // 데이터를 모두 힙에 넣는다.
    for(i=0; i<n; i++)
        arr[i] = HDelete(&heap); // 힙에서 다시 데이터를 꺼낸다.
}
int main(void)
{
    int arr[4] = {3,2,4,1};
    int i;
    HeapSort(arr, sizeof(arr)/sizeof(int), Pricomp);

    for(i=0; i<4; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}