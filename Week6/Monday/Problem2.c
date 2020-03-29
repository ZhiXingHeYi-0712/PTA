#include <stdio.h>

int main()
{
    int limit;
    if (scanf("%d", &limit) < 0) {
        perror("Input err");
        return 1;
    }

    if (limit < 2001 || limit > 2100) {
        puts("Invalid year!");
        return 0;
    }

    if (limit < 2004) {
        puts("None");
        return 0;
    }

    if (limit == 2100) {
        limit--;
    }

    for (int i = 2004; i <= limit; i += 4) {
        printf("%d\n", i);
    }
    return 0;
}