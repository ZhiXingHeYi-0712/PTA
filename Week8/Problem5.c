#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isArgsValid(int);
bool isNarcissisticNumber(int n);

int main()
{
    // int narcissisticNumber[] = {153, 370, 371, 407};

    int m, n;
    if (scanf("%d %d", &m, &n) < 0)
    {
        return 1;
    }

    if (!(isArgsValid(m) && isArgsValid(n) && m <= n))
    {
        printf("Invalid Value.");
        return 0;
    }

    for (int i = m; i <= n; i++)
    {
        if (isNarcissisticNumber(i))
        {
            printf("%d\n", i);
        }
    }
    return 0;
}

bool isArgsValid(int n)
{
    return (n >= 100 && n <= 999);
}

bool isNarcissisticNumber(int n)
{
    return pow(n / 100, 3) + pow(n / 10 % 10, 3) + pow(n % 10, 3) == n;
}
