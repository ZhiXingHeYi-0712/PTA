#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SWAP(X, Y)     \
    if ((X) != (Y))    \
    {                  \
        X = (X) + (Y); \
        Y = (X) - (Y); \
        X = (X) - (Y); \
    }

int searchMin(int *array, const int FROM, const int TO, const int LENGTH);
void selectSort(int *array, const int LENGTH);
void printfIntArray(int *, const int, const char *, const int, const bool);
void scanfIntArray(int *, const int, const char *);

int main()
{
    int n;
    scanf("%d", &n);

    // n == 1 按题目要求是未定义行为
    if (n == 1) {
        scanf("%d", &n);
        printf("%d", n);
        return 0;
    }

    int *array = malloc(sizeof(int) * n);
    scanfIntArray(array, n, "%d");
    selectSort(array, n);
    free(array);
    return 0;
}

/**
 *  NEWLINE: 换行标准，打印NEWLINE个数字就换行。传入-1不换行。
 */
void printfIntArray(int *intArray, const int LENGTH, const char *FORMAT, const int NEWLINE, const bool hasBottomSpace)
{
    int outputCount = 0;

    if (hasBottomSpace)
    {
        for (int i = 0; i < LENGTH; i++)
        {
            printf(FORMAT, intArray[i]);
            outputCount++;
            if (outputCount == NEWLINE)
            {
                printf("\n");
                outputCount = 0;
            }
        }
    }
    else
    {
        for (int i = 0; i < LENGTH; i++)
        {
            printf(FORMAT, intArray[i]);
            outputCount++;
            if (outputCount == NEWLINE)
            {
                printf("\n");
                outputCount = 0;
            }
            // 不是换行点且不是最后一个时补空格
            else if (outputCount != NEWLINE && i != LENGTH - 1)   
            {
                printf(" ");
            }
        }
    }

    if (outputCount != 0)   // 末尾无换行则换一行
    {
        printf("\n");
    }
}

void scanfIntArray(int *intArray, const int LENGTH, const char *FORMAT)
{
    for (int i = 0; i < LENGTH; i++)
    {
        scanf(FORMAT, &intArray[i]);
    }
}

/**
 * 选择排序
 */
void selectSort(int *array, const int LENGTH)
{
    for (int i = 0; i < LENGTH - 1; i++)
    {
        int minIndex = searchMin(array, i, LENGTH - 1, LENGTH);
        SWAP(array[i], array[minIndex]);
        printfIntArray(array, LENGTH, "%d", -1, false);
    }
}

/**
 * 在给定数组中搜索最小值
 * ARRAY: 数组
 * FROM: 起始下标，最小为0
 * TO: 终止下标，最大为LENGTH-1，搜索范围包括ARRAY[TO]
 * LENGTH: 数组长度
 * RETURN: 最小值的下标，传参不合法返回-1，多个可能值返回最小值
 * */
int searchMin(int *array, const int FROM, const int TO, const int LENGTH)
{
    if (FROM < 0 || TO > LENGTH - 1 || FROM > TO)
        return -1;
    int min = array[FROM];
    int minIndex = FROM;
    for (int i = FROM + 1; i <= TO; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
            minIndex = i;
        }
    }

    return minIndex;
}