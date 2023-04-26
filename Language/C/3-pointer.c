
// Min, Max 한 번에 구하기
//.h
#ifndef ALGORITHM_H
#define ALGORITHM_H


void get_min_max(const int nums[], const size_t length, int* out_min, int* out_max)

#endif

// .c
#include <assert.h>
#include <stddef.h>
#include "algorithm.h"


void get_min_max(const int nums[], const size_t length, int* out_min, int* out_max)
{
    size_t i;
    assert(length >= 1);

    *out_min = nums[0];
    *out_max = nums[0];

    for(i = 1; i < length; i++){
        if(*out_min > nums[i]){
            *out_min= nums[i];
        }
        if(*out_max > nums[i]){
            *out_max= nums[i];
        }
    }
}



// main

#define LENGTH(5)
void main(void)
{
    const int nums[LENGTH] = { 3, 10, 9, 8, 7};
    int min;
    int max;

    get_min_max(nums, LENGTH, &min, &max);

    return 0;
}

// int 메모리 뷰어
#include <stdio.h>

int main(void)
{
    const int NUM = 0x12345678;
    const char* NUM_ADDRESS = (char*)&NUM;
    size_t i;

    for(i=0; i < sizeof(NUM); ++i){
        printf("%hhx ", *(NUM_ADDRESS+i);
    }

}

// 두 배열이 겹치는가?
#ifndef MEMORY_H
#define MEMORY_H

#define TRUE(1)
#define FALSE(0)
#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

int is_overlap(int nums[], const size_t length1, int nums2[], const size_t length2);

#endif

#include "memory.h"

int is_overlap(int nums[], const size_t length1, int nums2[], const size_t length2)
{
return (nums < nums2 ? nums + length > nums2: nums+length2 > nums)
}

#include "memory.h"

int main(void)
{
    int nums = {1,2,3,4,5};
    int nums2 = {1,2,4,6};
    int* nums3 = nums + 2;
    char* result = NULL;

    const size_t NUMS3_LENGTH 5u;

    result = is_overlap(nums, ARRAY_LENGTH(nums), nums2, ARRAY_LENGTH(nums2)); // no
        result = is_overlap(nums, ARRAY_LENGTH(nums), nums3, ARRAY_LENGTH(nums3)); // yes



}