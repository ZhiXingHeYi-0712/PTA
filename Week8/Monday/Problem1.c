#include <stdio.h>

int printEquation(int, int);

int main()
{
    int n;  // n阶乘法表

    if (scanf("%d", &n) < 0) {
        return 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printEquation(j, i);
        }
        printf("\n");
    }

    return 0;
}

int printEquation(int a, int b)
{
    printf("%d*%d=%-4d", a, b, a*b);
    return 0;
}