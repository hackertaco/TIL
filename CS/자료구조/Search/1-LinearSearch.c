#include <stdio.h>
// 순차 탐색 코드

int LSearch(int ar[], int data, int length){
    int i;
    for( i=0; i<length; i++){
        if(ar[i] == data)
            return i;
    }
    return -1;
}

int main(void) 
{
    int arr[] = { 1,2,3,4,5 };
    int idx;

    idx = LSearch(arr, 3, sizeof(arr) / sizeof(int));
    if(idx == -1)
        printf("탐색 실패 \n");
    else
         printf("탐색 인덱스: %d \n", idx);
}