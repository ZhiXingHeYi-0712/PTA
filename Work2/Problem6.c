#include <stdio.h>

int main()
{
    int num1, num2;
    if (scanf("%d %d", &num1, &num2) < 0) {
        perror("Err.");
        return 1;
    }

    num1 += num2;
    num2 = num1 - num2;
    num1 -= num2;
    printf("a=%d,b=%d\n", num1, num2);
    return 0;
}