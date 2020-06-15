#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char* ArrayElement;

/**
 * 交换
 */
void swap(ArrayElement a, ArrayElement b) 
{
    ArrayElement tmp;
    tmp = a;
    a   = b;
    b   = tmp;
}

/**
 * 在给定数组中搜索最小值
 * ARRAY: 数组
 * FROM: 起始下标，最小为0
 * TO: 终止下标，最大为LENGTH-1，搜索范围包括ARRAY[TO]
 * LENGTH: 数组长度
 * CMP: 定义比较函数。如果a<b，则cmp(a, b) == 1; a>b, cmp(a, b) == 0
 * RETURN: 最小值的下标，传参不合法返回-1，多个可能值返回最小值
 * */
int searchMin(ArrayElement *array, const int FROM, const int TO,
    const int LENGTH, bool (*cmp)(ArrayElement, ArrayElement))
{
    if (FROM < 0 || TO > LENGTH - 1 || FROM > TO)
        return -1;
    ArrayElement min = array[FROM];
    int minIndex = FROM;
    for (int i = FROM + 1; i <= TO; i++)
    {
        if (cmp(array[i], min))
        {
            min = array[i];
            minIndex = i;
        }
    }

    return minIndex;
}

/**
 * 选择排序
 */
void selectSort(ArrayElement *array, const int LENGTH, bool (*cmp)(ArrayElement, ArrayElement))
{
    for (int i = 0; i < LENGTH - 1; i++)
    {
        int minIndex = searchMin(array, i, LENGTH - 1, LENGTH, cmp);
        swap(array[i], array[minIndex]);
    }
}

bool cmp(char* a, char* b)
{
    if (*a < *b) return true;
    else if (*a > *b) return false;
    else
    {
        a++;
        b++;
        return cmp(a, b);
    }   
}

int main()
{
    int n;
    scanf("%d", &n);
    fflush(stdin);

    char* nations[128];

    for (int i = 0; i < n; i++)
    {
        fgets(nations[i], 1024, stdin);
    }
    selectSort(nations, n, cmp);
    for (int i = 0; i < n; i++)
    {
        puts(nations[i]);
    }
}