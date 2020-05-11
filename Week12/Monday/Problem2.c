#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int* array = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", array+i);
    }

    int outputCount = 0;
    for (int i = 0; i < n-1; i++)
    {
        printf("%d", array[i+1]-array[i]);
        outputCount++;
        if (outputCount == 3) {
            printf("\n");
            outputCount = 0;
        } else if (i != n-2) {
            printf(" ");
        }
    }
}