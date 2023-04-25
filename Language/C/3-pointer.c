
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
