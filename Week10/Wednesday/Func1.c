#include <stdio.h>
#include <math.h>

int search(int n);

int main()
{
    int number;

    scanf("%d", &number);
    printf("count=%d\n", search(number));

    return 0;
}

/* 你的代码将被嵌在这里 */
int hasSameDigit(int n);

int search(int n)
{
    int count = 0;
    for (int i = 11; i < sqrt(n); i++)
    {
        if (hasSameDigit(i*i)) {
            count++;
        }
    }
    return count;
}

int hasSameDigit(int n)
{
    if (n >= 1000 || n <= 100)
    {
        return 0;
    }
    char num[4];
    sprintf(num, "%d", n);
    if (num[0] == num[1])
        return 1;
    if (num[0] == num[2])
        return 1;
    if (num[1] == num[2])
        return 1;
    return 0;
}