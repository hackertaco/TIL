
// 콜백함수
//.h
#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H


void register_error_handler(void (*handler)(const char* msg));
void log_error(const char* msg);

void default_error_handler(const char* msg);
#endif

// .c
#include <assert.h>
#include <time.h>
#include "error_handler.h"

static void(*s_handler)(const char*) = NULL;

void register_error_handler(void (*handler)(const char* msg))
{
    s_handler = handler;
}

void log_error(const char* msg)
{
    if(s_handler != NULL){
        s_handler(msg)
    }
}

void default_error_handler(const char* msg)
{
    time_t now;
    struct tm* local;
    now = time(NULL);

    local = localtime(&now);

}
// main

#include <stdio.h>
#include "error_handler.h"
#define TRUE(1)
#define FALSE(0)

void simple_stderr_print(const char* msg);
int run(void);
int main(void)
{
    int success;
    success = run();

    register_error_handler(default_error_handler);
    if(run() == FALSE){
    success = FALSE;

    }
    register_error_handler(simple_stderr_print);
    if(run() == FALSE){
        success = FALSE;

        }

        return success ? 0: 1;
}

int run(void)
{
int numerator;
int denominator;

if(denominator == 0){
    log_error("cannot divide by zero")
    return FAlSE;
}
}

// 구조체를 사용한 퀵 정렬

//.h
#ifndef USERDATA_H
#define USERDATA_H

typedef enum {
    SEX_MALE,
    SEX_FEMALE,
    SEX_UNKNOWN
}sex_t;

typedef struct {
    unsigned short id;
    unsigned char age;
    sex_t sex;
}userdata_t;
#endif

//user_sorter.h

#ifndef USER_SORTER_H
#define USER_SORTER_H

int compare_age_id(const void* p0, const void* p1);
int compare_desc_sex(const void* p0, const void* p1);

#endif

// .c

#include "userdata.h"
#include "user_sorter.h"

int compare_age_id(const void* p0, const void* p1)
{
    const userdata_t* user0 = p0;
    const userdata_t* user1 = p1;

    if(user0->age == user1->age){
        return user0->id - user1->id;
    }
    return user0->age - user1->age;
}
int compare_desc_sex(const void* p0, const void* p1)
{
    const userdata_t* user0 = p0;
    const userdata_t* user1 = p1;
    if(user0->age == user1->age){
            return user0->sex - user1->sex;
        }
        return user1->age - user0->age;

}

// main.c
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "userdata.h"
#include "user_sorter.h"

enum { NUM_USERS = 7};

int main(void)
{
    userdata_t users[NUM_USERS];
    size_t i;

    i = 0u;
    users[i].id = 482;
    users[i].sex =SEX_FEMALE;
    users[i++].age = 102;
    //... * 7명
    assert(i == NUM_USERS);

    puts("== sort by age, id ==");

    qsort(users, NUM_USERS, sizeof(userdata_t), compare_age_id);

}
// 기수 정렬
#ifndef USERDATA_H
#define USERDATA_H

typedef enum {
    SEX_MALE,
    SEX_FEMALE,
    SEX_UNKNOWN
}sex_t;

typedef struct {
    unsigned short id;
    unsigned char age;
    sex_t sex;
}userdata_t;
typedef struct {
    unsigned int sort_key;
    userdata_t user;

}radix_userdata_t;
#endif

// main.c
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "userdata.h"
enum { NUM_USERS = 7};
int compare_uint(const void* p0, const void* p1);

int main(void)
{
    radix_userdata_t users[NUM_USERS];
    size_t i;
     i = 0u;
        users[i].id = 482;
        users[i].sex =SEX_FEMALE;
        users[i++].age = 102;
        //... * 7명

        assert(i==NUM_USERS);
        for(i=0; i<NUM_USERS; ++i){
            unsigned char age = users[i].user.age;
            unsigned char id = users[i].user.id;

            users[i].sort_key = age << 16 | id; // 상위 16비트는 나이, 하위 16비트는 id
        }

        qsort(users, NUM_USERS, sizeof(radix_userdata_t), compare_uint);
// 내림차순
assert(SEX_UNKNOWN < 1 << 2);
        for(i=0; i<NUM_USERS; ++i){
                    unsigned char inv_age = 255 - users[i].user.age;
                    unsigned char sex = users[i].user.sex;

                    users[i].sort_key = age << 2 | sex; // 상위 비트는 나이, 하위 2비트는 sex
                }
        qsort(users, NUM_USERS, sizeof(radix_userdata_t), compare_uint);
}
int compare_uint(const void* p0, const void* p1)
{
    const unsigned int* i0 =p0;
    const unsigned int* i1 =p1;

    return *i0 - *i1;
}
