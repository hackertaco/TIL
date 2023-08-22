#include <stdio.h>

int Fibonacci(int n)
{
    if(n == 1)
        return 1;
    else if (n == 2)
    {
        return 2;
    }
    return Fibonacci(n-1) + Fibonacci(n-2);
    
}

int main(void)
{
    for(int i = 1; i<10;i++){
        printf("result: %d\n", Fibonacci(i));
    }
}