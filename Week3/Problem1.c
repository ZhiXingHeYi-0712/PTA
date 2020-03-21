#include <stdio.h>

int main()
{
    char input[4] = "152";

    printf("152 = %c + %c*10 + %c*100\n", input[2], input[1], input[0]); // 个位
    return 0;
}
