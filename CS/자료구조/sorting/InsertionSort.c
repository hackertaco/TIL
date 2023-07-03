#include <stdio.h>

void InserSort(int arr[], int n)
{
    int i, j;
    int insData;

    for(i=1;i<n;i++)
    {
        insData = arr[i];
        for(j=i-1; j>= 0; j--)
        {
            if(insData < arr[j])
                arr[j+1] = arr[j];
            else 
                break;
            
        }
        arr[j+1] = insData;
        
    }
}

int main(void)
{
    int arr[4] = {3,2,4,1};
    int i;
    InserSort(arr, sizeof(arr)/sizeof(int));

    for(i=0; i<4; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}