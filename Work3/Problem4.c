#include <stdio.h>
#define INPUT_ERROR 1

int main() {
    int scanningNumber, times=1;
    while (1)
    {
        if (scanf("%d", &scanningNumber) < 0) {
            perror("Input Err.");
            return INPUT_ERROR;
        }

        if (scanningNumber == 250) {
            printf("%d", times);
            return 0;
        }
        times++;
    }

    return 0;
}