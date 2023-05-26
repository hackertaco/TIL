
// 대소문자 구분없는 문자열 비교
//.h
#ifndef SHAPE_H
#define SHAPE_H



#endif

// .c
#include <type.h>
#include "string_utils.h"



int string_case_insensitive_compare(const char* str0, const char* str1 )
{
   int c1;
   int c2;

   c1 = tolower(*str0);
   c2 = tolower(*str1);

   while(c1 != '\0' && c1 == c2){
    c1 = tolower(++*str0);
    c2 = tolower(++*str1);
   }

   if(c1 == c2){
    return 0;
   }

   return c1 > c2 ? 1: -1;
}

// 문자열 버퍼 출력

#ifndef BUFFERED_PRINT_H
#define BUFFERED_PRINT_H
void buffered_print(const char* src)
#endif

#include <stdio.h>
#include <string.h>

#define BUFFER_LENGTH (32)
static size_t s_buffer_index = 0u;
static char s_buffer[BUFFER_LENGTH];

void buffered_print(const char* src)
{
    size_t num_left;
    const char* p = src;
    num_left = strlen(src);

    while(num_left > 0){
        size_t copy_count = BUFFER_LENGTH -1 - s_buffer_index;

        const int buffer_empty = s_buffer_index == 0;
        if(num_left < copy_count){
            copy_count = num_left;
        }
        s_buffer_index += copy_count;
        num_left -= copy_count;

        if(buffer_empty){
            strncpy(s_buffer, p, copy_count);
            s_buffer[s_buffer_index] = '\0';
        }else{
            strncat(s_buffer, p, copy_count);
        }
        p+= copy_count;

        if(s_buffer_index == BUFFER_LENGTH -1){
            s_buffer_index = 0;
        }

    }
}