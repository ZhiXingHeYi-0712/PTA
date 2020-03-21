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

    double divideAnswer = (double) num1 / num2;
    if (divideAnswer != (int) divideAnswer / 1) {
        // 不能整除
        printf("%d / %d = %.2f\n", num1, num2, divideAnswer);
    }
    else
    {
        // 可以整除
        printf("%d / %d = %d\n", num1, num2, (int) num1 / num2);
    }
    
    return 0;
}