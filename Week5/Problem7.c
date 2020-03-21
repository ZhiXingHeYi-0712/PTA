#include <stdio.h>

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

    printf("%d %d\n", max3(n1, n2, n3), min3(n1, n2, n3));

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
