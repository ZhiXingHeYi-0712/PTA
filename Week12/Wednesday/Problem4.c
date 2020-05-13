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

void printfIntArray(int *, const int, const char *, const int, const bool);
void scanfIntArray(int *, const int, const char *);
void BubbleSort(int *, const int, const int);

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int *array = malloc(sizeof(int) * n);
    scanfIntArray(array, n, "%d");
    BubbleSort(array, n, k);
    free(array);
    return 0;
}

void BubbleSort(int *intArray, const int LENGTH, const int OUTPUT_FLAG)
{
    for (int scanTime = 1; scanTime <= LENGTH - 1; scanTime++)
    {
        for (int i = 0; i < LENGTH - scanTime; i++)
        {
            if (intArray[i] > intArray[i+1]) {
                SWAP(intArray[i], intArray[i+1]);
            }
        }
        if (scanTime == OUTPUT_FLAG) {
            printfIntArray(intArray, LENGTH, "%d", -1, false);
            break;
        }
    }
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

    if (outputCount != 0) // 末尾无换行则换一行
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