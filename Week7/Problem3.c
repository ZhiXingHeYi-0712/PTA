#include <stdio.h>
#include <stdlib.h>

long getFactorial(const int, const long);

long getFactorial(const int N, const long lastFactorial) {
    return N == 1 ? 1 : N*lastFactorial;
}

int main() {
    double ans = 1; // 第一项
    int times;
    if (scanf("%d", &times) < 0) {
        return 1;
    }

    if (times >= 30) {
        printf("2.71828183");
        return 0;
    }

    double fac = 1;
    for (int i = 1; i <= times; i++) {
        fac = getFactorial(i, fac);
        ans += (double)1/fac;
    }

    printf("%.8f", ans);
}