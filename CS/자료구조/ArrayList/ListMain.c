#include <stdio.h>
#include "ArrayList.h"
// #include "ArrayList.c"

int main(void)
{
    /*** ArrayList�� ���� �� �ʱ�ȭ ***/
    List list;
    int data;
    ListInit(&list);

    /*** 5���� ������ ���� ***/
    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    /*** ����� �������� ��ü ��� ***/
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if (LFirst(&list, &data)) // ù ��° ������ ��ȸ
    {
        printf("%d ", data);

        while (LNext(&list, &data)) // �� ��° ������ ������ ��ȸ
            printf("%d ", data);
    }
    printf("\n\n");

    /*** ���� 22�� Ž���Ͽ� ��� ���� ***/
    if (LFirst(&list, &data))
    {
        if (data == 22)
            LRemove(&list);

        while (LNext(&list, &data))
        {
            if (data == 22)
                LRemove(&list);
        }
    }

    /*** ���� �� ����� ������ ��ü ��� ***/
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
    return 0;
    // List list;
    // int data;

    // ListInit(&list);

    // LInsert(&list, 111);
    // LInsert(&list, 111);
    // LInsert(&list, 222);
    // LInsert(&list, 222);
    // LInsert(&list, 333);

    // printf("현재 데이터수 %d \n", LCount(&list));

    // if(LFirst(&list, &data)){
    //     printf("%d ", data);
    //     while (LNext(&list, &data))
    //     {
    //         printf("%d \n", data);
    //     }

    // }

    // if(LFirst(&list, &data)){
    //     if(data == 222)
    //         LRemove(&list);
    //     while (LNext(&list, &data) )
    //     {
    //         if(data== 222)
    //             LRemove(&list);
    //     }

    // }
    //  printf("현재 데이터의 수 %d \n", LCount(&list));
    //  if(LFirst(&list, &data)){
    //     printf("%d ", data);
    //     while (LNext(&list, &data))
    //     {
    //         printf("%d \n", data);
    //     }

    // }

    // return 0;
}