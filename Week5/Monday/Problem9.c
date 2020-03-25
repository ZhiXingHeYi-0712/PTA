#include <stdio.h>

int max(int num1, int num2);
int max3(int num1, int num2, int num3);

int main() {
    int n1, n2, n3;
    if (scanf("%d %d %d", &n1, &n2, &n3) < 0)
    {
        perror("Err.");
        return 1;
    }

    int sum = n1 + n2 + n3;
    printf("%s", sum > (2*max3(n1, n2, n3)) ? "YES" : "NO");

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
