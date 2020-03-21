#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define INPUT_ERROR 1
#define DIVIDED_BY_ZERO 0
#define UNKNOWN_OPERATOR 0

#define DOUBLE_MIN 1e-15

int plus(double n1, double n2);
int multiply(double n1, double n2);
int minus(double n1, double n2);
int divide(double n1, double n2);

bool isDoubleEqualsZero(double num);

int main()
{
    double n1, n2;
    char operator;
    if (scanf("%lf%c%lf", &n1, &operator, &n2) < 0)
    {
        perror("Err input.");
        return INPUT_ERROR;
    }

    switch (operator)
    {
    case '+':
        plus(n1, n2);
        break;
    case '-':
        minus(n1, n2);
        break;
    case '*':
        multiply(n1, n2);
        break;
    case '/':
        divide(n1, n2);
        break;
    default:
        puts("Unknown operator!");
        return UNKNOWN_OPERATOR;
        break;
    }

    return 0;
}

int plus(double n1, double n2)
{
    printf("%.2f", n1 + n2);
    return 0;
}

int minus(double n1, double n2)
{
    return plus(n1, -n2);
}

int multiply(double n1, double n2)
{
    printf("%.2f", n1 * n2);
    return 0;
}

int divide(double n1, double n2)
{
    if (isDoubleEqualsZero(n2))
    {
        puts("Divisor can not be 0!");
        return DIVIDED_BY_ZERO;
    }
    printf("%.2f", n1 / n2);
    return 0;
}

bool isDoubleEqualsZero(double num)
{
    return fabs(num) <= DOUBLE_MIN ? true : false;
}