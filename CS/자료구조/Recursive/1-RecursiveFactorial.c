#include <stdio.h>
int RecursiveFactorial(int n) 
{
    if(n == 0)
        return 1;
    else   
        return n * RecursiveFactorial(n-1);
}

int main(void) 
{
    int result = RecursiveFactorial(5);
    printf("result is %d", result);
}