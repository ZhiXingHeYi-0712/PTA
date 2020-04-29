#include <stdio.h>

int getRabbit(int month);

int main()
{
    int N;
    if (scanf("%d", &N) < 0)
    {
        return 1;
    }
    for (int i = 1;; i++)
    {
        if (getRabbit(i) >= N)
        {
            printf("%d", i);
            return 0;
        }
    }
}

int getRabbit(int month)
{
    if (month <= 2)
    {
        return 1;
    }
    else
    {
        return getRabbit(month - 1) + getRabbit(month - 2);
    }
}