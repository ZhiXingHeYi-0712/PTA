#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define INPUT_ERROR 1
#define UNKNOWN_OPERATOR 0
#define DIVIDED_BY_ZERO 0

#define DOUBLE_MIN 1e-15

int plus(int n1, int n2);
int multiply(int n1, int n2);
int minus(int n1, int n2);
int divide(int n1, int n2);
int mod(int n1, int n2);

bool isDoubleEqualsZero(int num);

int main()
{
    int n1, n2;
    char operator;
    if (scanf("%d %c %d", &n1, &operator, &n2) < 0)
    {
        perror("INPUT ERROR");
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
    case '%':
        mod(n1, n2);
        break;
    default:
        puts("ERROR");
        return UNKNOWN_OPERATOR;
        break;
    }

    return 0;
}

int plus(int n1, int n2)
{
    printf("%d", n1 + n2);
    return 0;
}

int minus(int n1, int n2)
{
    return plus(n1, -n2);
}

int multiply(int n1, int n2)
{
    printf("%d", n1 * n2);
    return 0;
}

int divide(int n1, int n2)
{
    if (isDoubleEqualsZero(n2))
    {
        puts("Divisor can not be 0!");
        return DIVIDED_BY_ZERO;
    }
    printf("%d", (int) (n1 / n2));
    return 0;
}

int mod(int n1, int n2)
{
    int int_n2 = (int)n2;
    if (n2 == 0)
    {
        return DIVIDED_BY_ZERO;
    }
    printf("%d", ((int)n1) % int_n2);
    return 0;
}

bool isDoubleEqualsZero(int num)
{
    return fabs(num) <= DOUBLE_MIN ? true : false;
}