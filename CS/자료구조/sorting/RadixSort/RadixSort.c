#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM		10

void RadixSort(int arr[], int num, int maxLen)   // maxLen�� ���� �� �������� ����
{
	Queue buckets[BUCKET_NUM];
	int bi;
	int pos;
	int di;
	int divfac = 1;
	int radix;

	for(bi=0; bi<BUCKET_NUM; bi++)
		QueueInit(&buckets[bi]);

	for(pos=0; pos<maxLen; pos++)
	{ 
		for(di=0; di<num; di++)
		{
			radix = (arr[di] / divfac) % 10;

			Enqueue(&buckets[radix], arr[di]);
		}

		for(bi=0, di=0; bi<BUCKET_NUM; bi++)
		{
			while(!QIsEmpty(&buckets[bi]))
				arr[di++] = Dequeue(&buckets[bi]);
		}

		divfac *= 10;
	}	
}

int main(void)
{
	int arr[7] = {13, 212, 14, 7141, 10987, 6, 15};

	int len = sizeof(arr) / sizeof(int);
	int i;

	RadixSort(arr, len, 5);

	for(i=0; i<len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}