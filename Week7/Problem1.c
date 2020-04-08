#include <stdio.h>

int main() {
    long int ans = 1;
    int N;
    if (scanf("%d", &N) < 0) {
        return 1;
    }

    for (int i = 1; i <= N; i++) {
        ans *= i;
    }
    printf("%ld", ans);
    return 0;
}