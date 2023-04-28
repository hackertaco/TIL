
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

