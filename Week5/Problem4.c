#include <stdio.h>
#include <math.h>

#define INPUT_ERROR 1

int main()
{
    float height, weight;

    if (scanf("%f %f", &weight, &height) < 0)
    {
        perror("INPUT ERROR");
        return INPUT_ERROR;
    }

    float bmi = weight / (pow(height, 2));
    printf("%.1f\n", bmi);
    if (bmi > 25)
    {
        puts("PANG");
    }
    else
    {
        puts("Hai Xing");
    }

    return 0;
}