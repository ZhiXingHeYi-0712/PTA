#include <stdio.h>

#define INPUT_ERROR 1

int main()
{
    int day;
    if (scanf("%d", &day) < 0)
    {
        perror("INPUT ERROR");
        return INPUT_ERROR;
    }

    int trigger = day % 5;

    if (trigger <= 3 && trigger >= 1)
    {
        printf("Fishing in day %d", day);
    }
    else
    {
        printf("Drying in day %d", day);
    }

    return 0;
}