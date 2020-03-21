#include <stdio.h>

int main() {
    int x;
    if (scanf("%d", &x) < 0) {
        perror("Err.");
        return 1;
    }

    printf("%d", x > 0 ? x : -x);

    return 0;
}