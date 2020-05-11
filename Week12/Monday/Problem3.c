#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SWAP(X, Y) \
    X = (X) + (Y); \
    Y = (X) - (Y); \
    X = (X) - (Y);

struct ArrayElement
{
    int data;
    int index;
};

typedef struct ArrayElement *Element;

struct MaxMin
{
    Element max;
    Element min;
};

typedef struct MaxMin *MaxMinStruct;

MaxMinStruct max_min_ArrayElement(int *, const int, MaxMinStruct);
void printfIntArray(int *intArray, const int LENGTH, const char *FORMAT, const int NEWLINE);

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }

    MaxMinStruct result = malloc(sizeof(struct MaxMin));
    result->max = malloc(sizeof(struct ArrayElement));
    result->min = malloc(sizeof(struct ArrayElement));

    MaxMinStruct maxmin = max_min_ArrayElement(arr, n, result);

    // 当最大在第一个，实际上就是把最后一个元素放到最小元素的位置上
    if (maxmin->max->index == 0) {
        arr[0] = maxmin->min->data;
        arr[maxmin->min->index] = arr[n-1];
        arr[n-1] = maxmin->max->data;
    } else if (maxmin->min->index == n-1) {
        // 当最小在最后一个，实际上就是把第一个元素放到最大元素的位置上
        arr[maxmin->max->index] = arr[0];
        arr[0] = maxmin->min->data;
        arr[n-1] = maxmin->max->data;
    } else {
        SWAP(arr[0], arr[maxmin->min->index]);
        SWAP(arr[n-1], arr[maxmin->max->index]);
    }

    printfIntArray(arr, n, "%d ", -1);

    free(result->max);
    free(result->min);
    free(result);
}

MaxMinStruct max_min_ArrayElement(int *arr, const int LENGTH, MaxMinStruct result)
{
    result->max->data = INT_MIN;
    result->min->data = INT_MAX;
    result->max->index = 0;
    result->min->index = 0;

    for (int i = 0; i < LENGTH; i++)
    {
        if (arr[i] > result->max->data)
        {
            result->max->index = i;
            result->max->data  = arr[i];
        }
        if (arr[i] < result->min->data)
        {
            result->min->index = i;
            result->min->data  = arr[i];
        }
    }
    return result;
}

/**
 *  NEWLINE: 换行标准，打印NEWLINE个数字就换行。传入-1不换行。 
 */
void printfIntArray(int *intArray, const int LENGTH, const char *FORMAT, const int NEWLINE)
{
    int outputCount = 0;
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
