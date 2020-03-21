#include <stdio.h>

#define INPUT_ERROR 1

int main() {
    int x;
    if (scanf("%d", &x) < 0)
    {
        perror("INPUT ERROR");
        return INPUT_ERROR;
    }

    if (x >= 0) {
        printf("y=%f", (float) (x+3));
    } else {
        printf("y=%f", (float) x / 2);
    }

    return 0;
}