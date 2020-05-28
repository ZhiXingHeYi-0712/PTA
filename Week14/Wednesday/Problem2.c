#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define IS_UPPER_CASE(X) (X) >= 'A' && (X) <= 'Z'
#define IS_LOWER_CASE(X) (X) >= 'a' && (X) <= 'z'

void switchFromLowerAndUpperCases(char *c)
{
    const char d = 'a' - 'A';
    if (IS_UPPER_CASE(*c))
    {
        (*c) += d;
        return;
    };
    if (IS_LOWER_CASE(*c))
    {
        (*c) -= d;
        return;
    };
}

int main()
{
    char str[64];
    memset(str, 0, sizeof(char) * 64);
    scanf("%[^#]", str);

    for (int i = 0; i < strlen(str); i++)
    {
        switchFromLowerAndUpperCases(&str[i]);
    }

    puts(str);
}
