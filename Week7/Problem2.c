#include <stdio.h>

int main() {
    int MAX_BASE_NUMBER;
    long ans = 0, product = 1;
    if (scanf("%d", &MAX_BASE_NUMBER) < 1) {
        return 1;
    }
    for (int baseNumber = 1; baseNumber <= MAX_BASE_NUMBER; baseNumber++) {
        product = 1;
        for (int i = 1; i <= baseNumber; i++) {
            product *= i;
        }
        ans += product;
    }

    printf("%ld", ans);
    return 0;
}