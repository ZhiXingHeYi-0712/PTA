#include <stdio.h>
int main()
{
    double value1, value2;
    char n;
    scanf("%lf%c%lf", &value1, &op, &value2);
    switch (n)
    {
    case '+':
        printf("%.2lf\n", value1 + value2);
        break;
    case '-':
        printf("%.2lf\n", value1 - value2);
        break;
    case '*':
        printf("%.2lf\n", value1 * value2);
        break;
    case '/': //除法分两种情况讨论//
        if (value2 != 0)
        {
            printf("%.2lf\n", value1 / value2);
            break;
        }
        else
            printf("Divisor can not be 0!");
        break;
    default:
        printf("Unknown operator!");
        break;
    }
    return 0;
}
