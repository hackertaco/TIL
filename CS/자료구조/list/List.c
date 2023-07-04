#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
    List list;
    int data;
    int i;
    int sum;
    ListInit(&list);

    for(i=1; i<10;i++)
        LInsert(&list, i);

    printf("현재 데이터의 수: %d \n", LCount(&list));

    if(LFirst(&list, &data)){
        printf("%d ", data);
        sum = data;

        while(LNext(&list, &data))
            sum += data;
    }
    printf("현재 데이터의 합: %d \n", sum);

    if(LFirst(&list, &data)){
        if(data % 2 == 0 || data % 3 == 3)
            LRemove(&list);
        while(LNext(&list, &data))
        {    if(data % 2 == 0 || data % 3 == 3)
                LRemove(&list);
        }
    }
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if(LFirst(&list, &data)){
            printf("%d ", data);

            while(LNext(&list, &data))
                printf("%d ", data);
        }
    printf("\n\n");
    return 0;
}