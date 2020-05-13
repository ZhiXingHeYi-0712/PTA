#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void scanfIntArray(int *, const int, const char *);

int main()
{
    int numbers[10];
    scanfIntArray(numbers, 10, "%d");

    // 先把最小的非0放在第一个
    for (int digit = 1; digit < 10; digit++)
    {
        if (numbers[digit] != 0)
        {
            printf("%d", digit);
            numbers[digit]--;
            break;
        }
    }

    // 剩下的按次序输出
    for (int digit = 0; digit < 10; digit++)
    {
        for (int i = 0; i < numbers[digit]; i++) {
            printf("%d", digit);
        }
    }

    return 0;
}

void scanfIntArray(int *intArray, const int LENGTH, const char *FORMAT)
{
    for (int i = 0; i < LENGTH; i++)
    {
        scanf(FORMAT, &intArray[i]);
    }
}
