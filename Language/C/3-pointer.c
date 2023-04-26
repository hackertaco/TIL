
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

// 벡터 덧셈
#ifndef VECTOR_H
#define VECTOR_H

#define VECTOR_LENGTH(3)

void add_vec3(const int* v1, const int* v2, int* out_v3);

#endif

#include "vector.h"

void add_vec3(const int* v1, const int* v2, int* out_v3)
{

    size_t i = 0;
    for(i=0; i<VECTOR_LENGTH; ++i){
    *out_v3++ = *v1++ + *v2++;
    }


}

// 2D 배열을 배열의 배열로 바꾸기.

#ifndef VECTOR_H
#define VECTOR_H

#define VECTOR_LENGTH(3)

void add_vec3(const int* v1, const int* v2, int* out_v3);

#endif

#include <stdio.h>

int main(void)
{

    const int nums[3][5] = {
        {35, 50,65, 24,71},
        {5, 50,65, 24,71},
        {35, 30,65, 24,1},
    }
// 2d 배열은 연속적으로 저장되어있다. 그래서 nums[2] - nums[0] = 10
    const int* nums2[3];
    nums2[0] = nums[0];
    nums2[1] = nums[1];
    nums2[2] = nums[2];
// 배열의 배열은 주소만 저장되어있다. 그래서 &nums2[2] - &nums2[0] = 2
    printf("nums[0] address: %p\n", (void*) nums[0])


}
