#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define INPUT_ERROR 1

#define JAN 31
#define MAR 31
#define APR 30
#define MAY 31
#define JUN 30
#define JUL 31
#define AUG 31
#define SEP 30
#define OCT 31
#define NOV 30
#define DEC 31

bool isLeapYear(int year);



int main()
{
    int year, month, day;
    if (scanf("%d/%d/%d", &year, &month, &day) < 0)
    {
        perror("INPUT ERR.");
        return INPUT_ERROR;
    }

    const int FEB = isLeapYear(year) ? 29 : 28;

    int daysInMonth[12] = {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
    int result = 0;

    for (int i = 0; i < month - 1; i++)
    {
        result += daysInMonth[i];
    }
    result += day;
    printf("%d", result);

    return 0;
}

bool isLeapYear(int year)
{
    if (!(year % 100))
    {
        return !(year % 400); 
    }
    else
    {
        return !(year % 4);
    }
}