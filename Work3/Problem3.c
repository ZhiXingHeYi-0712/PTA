#include <stdio.h>
#define INPUT_ERROR 1
#define DIVIDED_BY_ZERO 0

int main()
{
    int dividend, divisor;
    if (scanf("%d %d", &dividend, &divisor) < 0) {
        perror("Err input.");
        return INPUT_ERROR;
    }

    if (divisor == 0) {
        printf("%d/%d=Error", dividend, divisor);
        return DIVIDED_BY_ZERO;
    }

    float result = (float) dividend / divisor;

    if (divisor < 0) {
        printf("%d/(%d)=%.2f", dividend, divisor, result);
        return 0;
    }
    printf("%d/%d=%.2f", dividend, divisor, result);

    return 0;
}