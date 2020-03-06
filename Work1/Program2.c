#include <stdio.h>
int main() {
    int F;
    if (scanf("%d", &F) <= 0) {
        perror("INPUT Err.");
        return 1;
    }
    printf("Celsius = %d", 5*(F-32)/9);
    return 0;
}

