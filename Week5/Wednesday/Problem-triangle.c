#include <stdio.h>
#include <stdbool.h>
/*
请编程从键盘上输入3个整数，判断这3个数是否可以构成一个三角形（条件：三条边均大于0且任意两边之和均大于第三边），如果可以则进一步判断是等边、等腰还是一般三角形，否则输出"-1"的信息。
*/
int max(int num1, int num2);
int max3(int num1, int num2, int num3);
int min(int n1, int n2);
int min3(int n1, int n2, int n3);

int main()
{
    int n1, n2, n3;
    if (scanf("%d %d %d", &n1, &n2, &n3) < 0)
    {
        perror("Err.");
        return 1;
    }

    int sum = n1 + n2 + n3;
    int max = max3(n1, n2, n3);
    int min = min3(n1, n2, n3);
    bool isTriangle = sum > (2 * max);

    if (!isTriangle) {
        puts("-1");
        return 0;
    }

    if (max == min) {
        puts("1");
        return 0;
    }

    if (n1 == n2 || n1 == n3 || n2 == n3) {
        puts("2");
        return 0;
    }

    puts("3");

    return 0;
}

int max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

int max3(int num1, int num2, int num3)
{
    return max(max(num1, num2), num3);
}

int min(int n1, int n2)
{
    return n1 > n2 ? n2 : n1;
}

int min3(int n1, int n2, int n3)
{
    return min(min(n1, n2), n3);
}
