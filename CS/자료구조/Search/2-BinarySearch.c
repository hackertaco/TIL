#include <stdio.h>

int BinarySearch(int ar[], int length, int data) 
{
    int first = 0;
    int last = length -1;
    int mid;
    while(first <= last) 
    {
        mid = (first + last) / 2;
        if(data == ar[mid])
            return mid;
        else 
            if (data > ar[mid])
                first = mid+1;
            else
                last = mid - 1;
        
    }
    return -1;
}

int main(void)
{
    int arr[] = {1,2,3,4,5};
    int idx;
    idx = BinarySearch(arr, sizeof(arr)/sizeof(int), 1);

    if(idx != -1)
        printf("index 값: %d\n", idx);
    else
        printf("존재하지 않습니다.");
}