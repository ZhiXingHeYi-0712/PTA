#include <stdio.h>
#include <stdlib.h>

int searchMax(int *array, const int FROM, const int TO, const int LENGTH);
void scanfIntArray(int *, const int, const char *);

int main()
{
    int n;
    scanf("%d", &n);
    int *array = malloc(sizeof(int) * n);
    scanfIntArray(array, n, "%d");

    int maxIndex = searchMax(array, 0, n - 1, n);
    printf("%d %d", array[maxIndex], maxIndex);
    free(array);
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

void scanfIntArray(int *intArray, const int LENGTH, const char *FORMAT)
{
    for (int i = 0; i < LENGTH; i++)
    {
        scanf(FORMAT, &intArray[i]);
    }
}