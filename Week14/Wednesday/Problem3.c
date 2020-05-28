#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IS_UPPER_CASE(X) (X) >= 'A' && (X) <= 'Z'
#define IS_LOWER_CASE(X) (X) >= 'a' && (X) <= 'z'

int findIndex(char *str, char c)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == c)
            return i;
    }
    return -1;
}

void encryptString(char *plain, char *secret, char *str)
{
    if (strlen(plain) != strlen(secret))
    {
        perror("密码本不匹配");
        return;
    }
    int index = -1;
    for (int i = 0; i < strlen(str); i++)
    {
        index = findIndex(plain, str[i]);
        if (index != -1)
            str[i] = secret[index];
    }
}

void decryptString(char *plain, char *secret, char *str)
{
    encryptString(secret, plain, str);
}

int main()
{
    char str[81];
    memset(str, 0, 81 * sizeof(char));
    fgets(str, 81 * sizeof(char), stdin);

    char plain[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char secret[27] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    encryptString(plain, secret, str);
    printf("%s", str);  // 后面不能加回车
}
