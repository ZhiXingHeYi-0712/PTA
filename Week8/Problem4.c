#include <stdio.h>

int printLine(int, const int);

int main()
{
    int n;
    if (scanf("%d", &n) < 0)
    {
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        printLine(i, n);
    }

    return 0;
}

int printLine(int line, const int TOTAL_LINES)
{
    if (line > TOTAL_LINES / 2 + 1) // 后半段
    {
        line = TOTAL_LINES + 1 - line;  // 换算到前半段
    }

    for (int i = 0; i < TOTAL_LINES + 1 - line * 2; i++)    // 前方补空
    {
        printf(" ");    
    }

    for (int i = 0; i < line * 2 - 1; i++) {    // 输出星号
        printf("* ");
    }
    printf("\n");
    return 0;
}
