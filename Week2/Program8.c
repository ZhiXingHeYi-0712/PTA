#include <stdio.h>
int main() {
    int num1, num2;
    if (scanf("%d %d", &num1, &num2) <= 0) {
        perror("INPUT Err.");
        return 1;
    }

    printf("%d", num1 * num2);
    return 0;
}