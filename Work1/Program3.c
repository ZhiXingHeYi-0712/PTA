#include <stdio.h>

int main() {
    int numbers[4];
    if (scanf("%d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3]) <= 0) {
        perror("INPUT Err.");
        return 1;
    }
    int sum = numbers[0] + numbers[1] + numbers[2] + numbers[3];
    printf("Sum = %d; Average = %.1f",sum, (float) sum / 4 );
    return 0;
}