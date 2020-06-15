#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    int maxLength = 0;
    char maxString[82];
    char thisString[82];

    memset(maxString, 0, sizeof(char) * 82);
    memset(thisString, 0, sizeof(char) * 82);
    fflush(stdin);
    for (int i = 0; i < n; i++) {
        fgets(thisString, 81, stdin);
        if (strlen(thisString) > maxLength) {
            maxLength = strlen(thisString);
            strcpy(maxString, thisString);
        }
    }
    printf("The longest is: %s", maxString);
}