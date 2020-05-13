#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchMax(int *array, const int FROM, const int TO, const int LENGTH);

int main()
{
    int numberStats[10];
    memset(numberStats, 0, sizeof(int) * 10);

    scanf("%*d"); // 吃掉第一个和回车
    getchar();

    int c;
    while (1)
    {
        c = getchar();
        if (c == '\n')
        {
            break;
        }
        else if (c != ' ')
        {
            numberStats[c - '0']++;
        }
    }

    int maxIndex = searchMax(numberStats, 0, 9, 10);
    int max = numberStats[maxIndex];
    int outputTime = 0, outputCount = 0;;
    printf("%d: ", max);
    for (int i = 0; i < 10; i++)
    {
        if (numberStats[i] == max)
        {
            outputTime++;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if(numberStats[i] == max) {
            printf("%d", i);
            outputCount++;
            if (outputCount != outputTime) {
                printf(" ");
            }
        }
    }

    return 0;
}

/**
 * 在给定数组中搜索最大值
 * ARRAY: 数组
 * FROM: 起始下标，最小为0
 * TO: 终止下标，最大为LENGTH-1，搜索范围包括ARRAY[TO]
 * LENGTH: 数组长度
 * RETURN: 最大值的下标，传参不合法返回-1，多个可能返回值返回最小值
 * */
int searchMax(int *array, const int FROM, const int TO, const int LENGTH)
{
    if (FROM < 0 || TO > LENGTH - 1 || FROM > TO)
        return -1;
    int max = array[FROM];
    int maxIndex = FROM;
    for (int i = FROM + 1; i <= TO; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}