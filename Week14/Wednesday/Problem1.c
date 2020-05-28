#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define IS_UPPER_CASE(X) (X) >= 'A' && (X) <= 'Z'
#define GET_UPPER_CASE_INDEX(X) ((X) - 'A')

int main()
{
    char str[81];
    memset(str, 0, 81 * sizeof(char));
    fgets(str, 80 * sizeof(char), stdin);

    bool alphabet[26];
    memset(alphabet, 0, 26 * sizeof(bool));

    bool output = false;

    for (int i = 0; i < strlen(str); i++)
    {
        if (IS_UPPER_CASE(str[i]) && (!alphabet[GET_UPPER_CASE_INDEX(str[i])]))
        {
            alphabet[GET_UPPER_CASE_INDEX(str[i])] = true;
            putchar(str[i]);
            output = true;
        }
    }

    if (!output)
        puts("Not Found");
}
