#include <stdio.h>
#define INPUT_ERROR 1
#define FINISH 0

int main()
{
    int sum = 0;
    int i;
    while (1)
    {
        if (scanf("%d", &i) < 0)
        {
            perror("INPUT ERROR");
            return INPUT_ERROR;
        }
        if (i <= 0)
        {
            break;
        }
        if (i % 2)
        {
            sum += i;
        }
    }
    printf("%d", sum);

    return FINISH;
}