#include <stdio.h>
int main()
{
    double a, b, d;
    char cal;
    scanf("%lf%c%lf", &a, &cal, 1, &b);
    if (cal == '+')
    {
        printf("%.2lf", a + b);
    }
    else if (cal == '-')
    {
        printf("%.2lf", a - b);
    }
    else if (cal == '*')
    {
        printf("%.2lf", a * b);
    }
    else if (cal == '/')
    {
        if (b == 0)
            printf("Divisor can not be 0!");
        else
            printf("%.2lf", a / b);
    }
    else
        printf("Unknown operator!");
    return 0;
}
