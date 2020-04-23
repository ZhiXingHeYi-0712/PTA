#include <stdio.h>
#include <math.h>

int main()
{
    long h, n;
    scanf("%ld %ld", &h, &n);
    if (n == 0) {
        printf("0.0 0.0", (double)h, (double)h);
        return 0;
    }
    printf("%.1f %.1f", (3.0-pow(2, 2-n))*h, pow(2, -n)*h);
    return 0;
}