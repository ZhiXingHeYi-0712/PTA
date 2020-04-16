#include <stdio.h>
long getFactorial(const int, const long);

int main()
{
    int n;
    long int sum = 0;
    long int tmp = 1;

    if (scanf("%d", &n) < 0)
    {
        return 1;
    }

    for (int i = 1; i <= n; i++)
    {
        tmp = getFactorial(i, tmp);
        sum += tmp;
    }

    printf("%ld", sum);
    return 0;
}

long getFactorial(const int N, const long lastFactorial)
{
    return N == 1 ? 1 : N * lastFactorial;
}
