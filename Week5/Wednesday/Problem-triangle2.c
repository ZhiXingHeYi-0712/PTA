#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define INPUT_ERROR 1

struct pointD2
{
    double x;
    double y;
};

typedef struct pointD2 Point;

double max(double num1, double num2);
double max3(double num1, double num2, double num3);
bool isTriangle(const double L1, const double L2, const double L3);
double getLength(const Point *p1, const Point *p2);
double getSize(const double L1, const double L2, const double L3);
int setPoint(Point *p);

int main()
{
    Point *points[3];

    for (int i = 0; i < 3; i++)
    {
        points[i] = calloc(sizeof(Point), 1);
        setPoint(points[i]);
    }

    const double L1 = getLength(points[0], points[1]);
    const double L2 = getLength(points[0], points[2]);
    const double L3 = getLength(points[1], points[2]);

    if (isTriangle(L1, L2, L3))
    {
        printf("L = %.2f, A = %.2f", L1 + L2 + L3, getSize(L1, L2, L3));
    }
    else
    {
        puts("Impossible");
    }

    return 0;
}

int setPoint(Point *p)
{
    if (scanf("%lf %lf", &p->x, &p->y) < 0)
    {
        perror("Input Err.");
        return 1;
    }
    return 0;
}

// 返回两点间距
double getLength(const Point *p1, const Point *p2)
{
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

double max(const double num1, const double num2)
{
    return num1 > num2 ? num1 : num2;
}

double max3(const double num1, const double num2, const double num3)
{
    return max(max(num1, num2), num3);
}

bool isTriangle(const double L1, const double L2, const double L3)
{
    double sum = L1 + L2 + L3;
    return sum > (2 * max3(L1, L2, L3));
}

double getSize(const double L1, const double L2, const double L3)
{
    const double P = (L1 + L2 + L3) / 2;
    return sqrt(P * (P - L1) * (P - L2) * (P - L3));
}
