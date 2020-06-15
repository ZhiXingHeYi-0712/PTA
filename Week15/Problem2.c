#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define DIGIT_CHAR_TO_INT(CH) ((CH) - '0')

bool isValid(char *str)
{
    int sum = 0;
    int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char check[] = {'1',
                    '0',
                    'X',
                    '9',
                    '8',
                    '7',
                    '6',
                    '5',
                    '4',
                    '3',
                    '2'};
    if (strlen(str) != 19)
        return false;
    for (int i = 0; i < 17; i++)
    {
        if (!isdigit(str[i]))
            return false;
        sum += DIGIT_CHAR_TO_INT(str[i]) * weight[i];
    }
    int z = sum % 11;
    return check[z] == str[17];
}

int main()
{
    int n;
    scanf("%d", &n);
    fflush(stdin);
    char str[32];
    char output[1801];
    bool allPass = true;
    memset(str, 0, sizeof(char) * 32);
    memset(output, 0, sizeof(char) * 32);
    
    for (int i = 0; i < n; i++)
    {
        fgets(str, 32, stdin);
        fflush(stdin);
        if (!isValid(str)) {
            strcat(output, str);
            allPass = false;
        }
    }

    if (allPass) {
        puts("All passed");
    } else {
        printf("%s", output);
    }
}