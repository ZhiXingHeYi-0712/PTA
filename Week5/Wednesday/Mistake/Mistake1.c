#include <stdio.h>
#include <math.h>
#define DOUBLE_MIN 1e-15

int main()
{
    double a, b, d; // WARNING: UNUSED varible d;
    char cal;
    // scanf("%lf%c%lf", &a, &cal, 1, &b);
    scanf("%lf%c%lf", &a, &cal, &b);

    if (cal == '+')
    {
        // printf("%.2lf", a + b);
        printf("%.2f", a + b);
    }
    else if (cal == '-')
    {
        // printf("%.2lf", a - b);
        printf("%.2f", a - b);
    }
    else if (cal == '*')
    {
        // printf("%.2lf", a * b);
        printf("%.2f", a * b);
    }
    else if (cal == '/')
    {
        // if (b == 0)
        if (fabs(b) < DOUBLE_MIN)
            printf("Divisor can not be 0!");
        else
            // printf("%.2lf", a / b);
            printf("%.2f", a / b);
    }
    else
        printf("Unknown operator!");
    return 0;
}
