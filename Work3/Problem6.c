#include <stdio.h>

int main()
{
    int num1, num2;
    if (scanf("%d %d", &num1, &num2) < 0)
    {
        perror("Err.");
        return 1;
    }

    printf("%d + %d = %d\n", num1, num2, num1 + num2);
    printf("%d - %d = %d\n", num1, num2, num1 - num2);
    printf("%d * %d = %d\n", num1, num2, num1 * num2);
    printf("%d / %d = %d\n", num1, num2, num1 / num2);
    return 0;
}