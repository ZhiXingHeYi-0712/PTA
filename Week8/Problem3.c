#include <stdio.h>

int main()
{
    int n, thisNum = 1;
    if (scanf("%d", &n) < 0)
    {
        return 1;
    }

    for (int i = n; i >= 0; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%4d", thisNum++);
        }
        if (i != 0) printf("\n");
    }
    return 0;
}