#include <stdio.h>

#define INPUT_ERROR 1

int main() {
    int x;
    if (scanf("%d", &x) < 0)
    {
        perror("INPUT ERROR");
        return INPUT_ERROR;
    }

    printf("%s", (x >= 99 && x <= 1000) ? "yes" : "no");
    return 0;
}