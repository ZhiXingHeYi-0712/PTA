#include <stdio.h>
#include <math.h>
#define DOUBLE_MIN 1e-15

int main()
{
    double value1, value2;
    char n;
    // scanf("%lf%c%lf", &value1, &op, &value2);
    scanf("%lf%c%lf", &value1, &n, &value2);
    switch (n)
    {

    // printf全部%.2lf->%.2f
    case '+':
        printf("%.2f\n", value1 + value2);
        break;
    case '-':
        printf("%.2f\n", value1 - value2);
        break;
    case '*':
        printf("%.2f\n", value1 * value2);
        break;
    case '/': //除法分两种情况讨论
        if (fabs(value2) >= DOUBLE_MIN)
        {
            printf("%.2f\n", value1 / value2);
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
