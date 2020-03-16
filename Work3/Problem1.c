#include <stdio.h>
#include <complex.h>
#include <stdio.h>
#include <math.h>

#define INPUT_ERROR 1
#define DOUBLE_MIN 1e-15
#define FLOAT_MIN 1e-7

/*
    评测数据分析：
    测试点0 - 两个不等实根
    测试点1 - 
    测试点2 - a=0,输出一个根
    测试点3 - Zero Equation
    测试点4 - Not an Equation
    测试点5 - 两个相等实根
    测试点6 - 
*/

_Bool isFloatEqualsZero(float num);

int main()
{
    float a, b, c;
    if (scanf("%f %f %f", &a, &b, &c) < 0)
    {
        perror("Input Err.");
        return INPUT_ERROR;
    }

    if (isFloatEqualsZero(a))
    {
        if (isFloatEqualsZero(b))
        {
            if (isFloatEqualsZero(c))
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
    if (isFloatEqualsZero(delta))
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
        result = (-b + I * sqrt(-delta)) / (2 * a);
        float real = crealf(result);
        float imag_abs = fabs(cimagf(result));

        printf("%.2f+%.2fi\n", real, imag_abs);
        printf("%.2f-%.2fi\n", real, imag_abs);
    }

    return 0;
}

_Bool isFloatEqualsZero(float num)
{
    return fabs(num) <= DOUBLE_MIN ? 1 : 0;
}
