#include <stdio.h>
int RecursiveBS(int arr[], int data, int start, int end)
{
    int mid;
    if(start > end)
        return -1;
    mid = (start + end) / 2;
    if(arr[mid] == data)
        return mid;
    else if(arr[mid] > data)
        return RecursiveBS(arr, data, mid+1, end);
    else    
        return RecursiveBS(arr, data, start, mid - 1);
}

int main(void)
{
    int array[] = {1, 2, 4, 5, 6};

    int result = RecursiveBS(array, 3, 0, sizeof(array)/ sizeof(int));
    printf("result: %d", result);
}
