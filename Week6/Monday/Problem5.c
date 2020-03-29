#include <stdio.h>

int max(int num1, int num2);

int main()
{
    int a, b, r;
    if (scanf("%d %d", &a, &b) < 0)
    {
        perror("INPUT ERROR");
        return 1;
    }
    int originA = a;
    int originB = b;
    if (a < b)  // swap
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }

    // a >= b
    r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    int maxFactor = b;
    int maxMultiple = originA * originB / maxFactor; 
    printf("%d %d", maxFactor, maxMultiple);

    return 0;
}

int max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}
