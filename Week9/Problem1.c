#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define IS_LOWERCASE_LETTER(C) (('a' <= (C)) && ((C) <= 'z'))
#define IS_UPPERCASE_LETTER(C) (('A' <= (C)) && ((C) <= 'Z'))
#define IS_LETTER(C) (IS_LOWERCASE_LETTER(C) || IS_UPPERCASE_LETTER(C))

void *encryptString(char *inputStr);
char switchFrom_LowerCase_And_Capitalization(char c);

int main()
{
    char *inputStr = malloc(sizeof(char) * 512);
    if (scanf("%[^\n]%*c", inputStr) < 0)
    {
        return 1;
    }
    encryptString(inputStr);
    printf("%s", inputStr);
    return 0;
}

void *encryptString(char *inputStr)
{
    char *c = inputStr;
    while (*c != '\0')
    {
        if (*c == 'z')
        {
            *c = 'A';
            c += sizeof(char);
            continue;
        }
        else if (*c == 'Z')
        {
            *c = 'a';
            c += sizeof(char);
            continue;
        }
        else if (IS_LETTER(*c))
        {
            *c = switchFrom_LowerCase_And_Capitalization(*c + 1);
        }
        c += sizeof(char);
    }
    return inputStr;
}

char switchFrom_LowerCase_And_Capitalization(char c)
{
    if (IS_LOWERCASE_LETTER(c))
    {
        return c - ('a' - 'A');
    }
    else if (IS_UPPERCASE_LETTER(c))
    {
        return c + ('a' - 'A');
    }
    else
    {
        return c;
    }
}