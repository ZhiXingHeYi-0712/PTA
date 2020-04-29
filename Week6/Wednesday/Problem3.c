#include <stdio.h>
#include <stdlib.h>

#define INPUT_ERROR 0

typedef struct frac *Frac;

struct frac
{
    // 这里用double是因为需要存储很大的数据
    double numerator;   // 分子
    double denominator; // 分母
    double (*getValue)(Frac frac);
};

Frac createFrac(int numerator, int denominator);
double getFracValue(const Frac F);

int main()
{
    double sum = 0;
    int N;
    if (scanf("%d", &N) < 0)
    {
        return INPUT_ERROR;
    }
    Frac f  = createFrac(2, 1);
    for (int i = 0; i < N; i++)
    {
        sum += (f->getValue)(f);

        f->numerator = f->numerator + f->denominator;
        f->denominator = f->numerator - f->denominator;
    }
    printf("%.2f", sum);
    free(f);
    return 0;
}

double getFracValue(const Frac F)
{
    return (double)F->numerator / F->denominator;
}

Frac createFrac(int numerator, int denominator)
{
    Frac f = malloc(sizeof(struct frac));
    f->numerator = numerator;
    f->denominator = denominator;
    f->getValue = getFracValue;
    return f;
}
