#include <stdio.h>
#include <complex.h>
#include <stdio.h>
#include <math.h>

#define INPUT_ERROR 1
#define DOUBLE_MIN 1e-15

int isDoubleEqualsZero(double num);

int main()
{
    float a, b, c;
    if(scanf("%f %f %f", &a, &b, &c) < 0) {
        perror("Input Err.");
        return INPUT_ERROR;
    }

    if (isDoubleEqualsZero(a))
    {
        if (isDoubleEqualsZero(b))
        {
            if (isDoubleEqualsZero(c))
            {
                // 都为0
                printf("Zero Equation\n");
                return 0;
            }

            // a=b=0
            printf("Not An Equation\n");
            return 0;
        }
        // 如果a=0,一个根
        printf("%.2f\n", -c / b);
        return 0;
    }

    // 判别式
    double delta = pow(b, 2) - 4 * a * c;

    // 两个相等实根
    if (isDoubleEqualsZero(delta))
    {
        goto oneSolution;
    }

    // 两个不等实根
    if (delta > 0)
    {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        printf("%.2f\n", x1);

    oneSolution:
    {
        double x2 = (-b - sqrt(delta)) / (2 * a);
        printf("%.2f\n", x2);
        return 0;
    }
    }

    if (delta < 0)
    {
        float complex result;
        result = (-b+I * sqrt(-delta))/(2*a);
        float real = crealf(result);
        float imag_abs = fabs(cimagf(result));
        
        printf("%.2f+%.2fi\n", real, imag_abs);
        printf("%.2f-%.2fi\n", real, imag_abs);
    }

    return 0;
}

int isDoubleEqualsZero(double num)
{
    return fabs(num) <= DOUBLE_MIN ? 1 : 0;
}
