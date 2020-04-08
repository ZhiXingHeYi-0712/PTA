#include <stdio.h>

int main()
{
    int i = 10;
    while (1)
    {
        if ((i % 5 == 1) && (i % 6 == 5) && (i % 7 == 4) && (i % 11 == 10))
        {
            printf("%d", i);
            return 0;
        }
        i += 11;
    }
    return 0;
}