#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);

int main()
{
    int m, n, count = 0, sum = 0;
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; i++)
    {
        if (isPrime(i))
        {
            sum += i;
            count++;
        }
    }
    printf("%d %d", count, sum);
    return 0;
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
