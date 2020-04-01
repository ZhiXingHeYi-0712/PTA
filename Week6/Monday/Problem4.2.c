#include <stdio.h>
#define INPUT_ERROR 1

int main() {
    int sum;
    char digit;
    int length = 0;
    while (1)
    {
        if (scanf("%c", &digit) < 0) {
            perror("INPUT ERROR");
            return INPUT_ERROR;
        }

        if (digit == '\n') {
            break;
        }

        sum += (digit - '0');
        length ++;
        
    }
    printf("%d %d\n", length, sum);

    return 0;
}