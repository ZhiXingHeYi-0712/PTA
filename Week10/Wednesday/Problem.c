#include <stdio.h>
#include <math.h>
int isPrime(int n);

int main()
{
    int limit;
    int count = 0;
    scanf("%d", &limit);
    for (int i = 1; i <= limit; i++)
    {
        int num = (1 << i) - 1;
        if (isPrime(num))
        {
            count++;
            printf("%d\n", num);
        }
    }
    if (count == 0)
    {
        printf("None");
    }
    return 0;
}

int isPrime(int n)
{
    if (n == 1)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (!(n % i))
            return 0;
    }
    return 1;
}