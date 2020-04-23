#include <stdio.h>
#include <math.h>

#define MERSENNE_PRIME(N) (int) (pow(2, (N)) - 1)

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("None");
        return 0;
    }
    for (int i = 2; i <= n; i++)
    {
        if (i == 2 || i == 3 || i == 5 || i == 7 || i == 13 || i == 17 || i == 19) {
            printf("%d\n", MERSENNE_PRIME(i));
        }
    }
}