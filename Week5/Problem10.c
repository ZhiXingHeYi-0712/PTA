#include <stdio.h>
#include <stdbool.h>

#define INPUT_ERROR 1

bool isLeapYear(int year);

int main() {
    int year;
    if (scanf("%d", &year) < 0) {
        perror("INPUT ERR.");
        return INPUT_ERROR;
    }

    printf("%s", isLeapYear(year) ? "Intercalary year" : "Common year");

    return 0;
}

bool isLeapYear(int year)
{
    if (!(year % 100))
    {
        return !(year % 400); // æ•´ç™¾å¹´
    }
    else
    {
        return !(year % 4);
    }
}