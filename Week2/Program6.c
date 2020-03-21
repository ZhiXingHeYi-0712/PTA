#include <stdio.h>
int main() {
    int day;
    if (scanf("%d", &day) <= 0) {
        perror("INPUT Err.");
        return 1;
    }

    if (day == 5) {
        printf("7\n");
        return 0;
    }
    
    printf("%d\n", (day + 2) % 7);
    return 0;
}