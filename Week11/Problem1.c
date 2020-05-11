#include <stdio.h>
long fib(int);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%ld", fib(n));
    return 0;
}

long fib(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}