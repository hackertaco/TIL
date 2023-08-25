#include "LinkedList.h"
#include <stdio.h>

int WhoIsProceed(int d1, int d2)
{
    if(d1 < d2)
        return 0;
    else
        return 1;
}

int main(void)
{
    List list;

    ListInit(&list);
    setSortRule(&list, WhoIsProceed);
    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    printf("data count : %d\n", LCount(&list));


}
