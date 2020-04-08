#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef double FracDataType;

struct frac
{
    FracDataType numerator;   // 分子
    FracDataType denominator; // 分母
};

typedef struct frac *Frac;

double getFracValue(const Frac F);
bool isLoopContinue(const Frac, const double);
Frac createFrac();
Frac nextFrac(const int, Frac);

int main()
{
    double limit, halfAns = 0;
    if (scanf("%lf", &limit) < 0)
    {
        return 1;
    }

    Frac f = createFrac();
    for (int i = 1; isLoopContinue(f, limit); i++)
    {
        f = nextFrac(i, f);
        halfAns += getFracValue(f);
    }

    printf("%.6f", halfAns * 2);

    return 0;
}

bool isLoopContinue(const Frac F, const double limit)
{
    return F->denominator == 0 ? true : !(getFracValue(F) < limit);
}

double getFracValue(const Frac F)
{
    return (double)F->numerator / F->denominator;
}

Frac createFrac()
{
    Frac f = malloc(sizeof(struct frac));
    f->denominator = 0;
    f->numerator = 0;
    return f;
}

Frac nextFrac(const int NUM, Frac f)
{
    if (f->denominator == 0)
    {
        f->denominator = 1;
        f->numerator = 1;
    }
    else
    {
        f->numerator = f->numerator * (NUM - 1);
        f->denominator = f->denominator * (2 * NUM - 1);
    }
    return f;
}