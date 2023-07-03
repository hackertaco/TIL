#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    int low = left+1;
    int high = right;

    while(low <= high)
    {
        while(pivot >= arr[low] && low <= right)
            low++;
        while(pivot <= arr[high] && high >= left+1)
            high--;
        if(low <= high)
            Swap(arr, low, high);
        
    }
    Swap(arr, left, high);
    return high;
}

void QuickSort(int arr[], int left, int right)
{
    if(left <= right)
    {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot -1);
        QuickSort(arr, pivot+1, right);
    }

}

int main(void)
{
    int arr[7] = {3,2,4,1,7,6,5};
    int len = sizeof(arr)/sizeof(int);

    int i;
    QuickSort(arr, 0, sizeof(arr)/ sizeof(int) -1);
    for(i=0;i<len;i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}