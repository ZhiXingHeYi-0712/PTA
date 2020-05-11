#include <stdio.h>

void printfIntArray(int *intArray, const int LENGTH, const char *FORMAT, const int NEWLINE);
int main()
{
    int fib[12];
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < 12; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    printfIntArray(fib, 12, "%6d", 3);
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