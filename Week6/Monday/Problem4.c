#include <stdio.h>
#include <string.h>
#define INPUT_ERROR 1

int main() {
    int sum = 0;
    char input[11];
    if (scanf("%s", input) < 0) {
        perror("INPUT ERROR");
        return INPUT_ERROR;
    }

    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        sum += (input[i] - '0');
    }

    printf("%d %d", length, sum);
    return 0;
}