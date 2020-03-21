#include <stdio.h>

int main()
{
    float f_num1, f_num2;
    int i_num;
    char ch;
    if (scanf("%f %d %c %f", &f_num1, &i_num, &ch, &f_num2) <= 0)
    {
        perror("INPUT Err.");
        return 1;
    }
    printf("%c %d %.2f %.2f", ch, i_num, f_num1, f_num2);
    return 0;
}