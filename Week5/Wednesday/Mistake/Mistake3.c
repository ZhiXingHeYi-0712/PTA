#include <stdio.h>
#include <math.h>
#define DOUBLE_MIN 1e-15

int main()
{
    double a, b;
    char op;
    scanf("%lf%c%lf", &a, &op, &b);
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%')
    {
        if (op == '/')
        {
            if (fabs(b) < DOUBLE_MIN)
            {
                printf("Divisor can not be 0!");
            }
            else
            {
                printf("%.2f", a / b);
            }
        }
        else if (op == '+')
        {
            printf("%.2f", a + b);
        }
        else if (op == '-')
        {
            printf("%.2f", a - b);
        }
        else if (op == '*')
        {
            printf("%.2f", a * b);
        }
        else if (op == '%')
        {
            if ((int)a % (int)b == 0)
            {
                printf("Unknown operator!");
            }
            else
            {
                printf("%d", (int)a % (int)b);
            }
        }
    }
    else
    {
        // (printf "Unknown operator!");
        printf("Unknown operator!");
    }
    return 0;
}
