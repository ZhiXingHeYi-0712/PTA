#include <stdio.h>
#include <limits.h>

int main() {
    int n, a, min = INT_MAX;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {     
        scanf("%d", &a);
        if (a < min) min = a;
    }
    printf("min = %d", min);
    
    return 0;
}