#include <stdio.h>

int gcd(int x, int y);

int main()
{
    int x, y;

    scanf("%d %d", &x, &y);
    printf("%d\n", gcd(x, y));

    return 0;
}

/* 你的代码将被嵌在这里 */

int gcd(int x, int y)
{
    int r;
    if (x < y) // swap
    {
        x = x + y;
        y = x - y;
        x = x - y;
    }

    // a >= b
    r = x % y;
    while (r != 0)
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}