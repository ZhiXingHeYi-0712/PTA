#include <stdio.h>
int main() {
    int length, width;
    if (scanf("%d %d", &length, &width) <= 0) {
        perror("INPUT Err.");
        return 1;
    }

    if (length <= 0 || width <= 0) {
        // use positive number.
        return 1;
    }

    printf("C = %d\n", 2 * (length + width));
    printf("S = %d\n", length * width);
    return 0;
}