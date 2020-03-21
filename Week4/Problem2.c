#include <stdio.h>
#define PRICE_90 6.95
#define PRICE_93 7.44
#define PRICE_97 7.93

#define M_PRICE_OFF 0.05
#define E_PRICE_OFF 0.03

#define INPUT_ERROR 1
#define INVALID_PETROL_NUMBER 2

int main()
{
    double money;
    int liter, number; // 汽油号
    char type;

    // 输入
    if (scanf("%d %d %c", &liter, &number, &type) < 0)
    {
        perror("Err.");
        return INPUT_ERROR;
    }

    // 原价
    switch (number)
    {
    case 90:
        money = PRICE_90 * liter;
        break;
    case 93:
        money = PRICE_93 * liter;
        break;
    case 97:
        money = PRICE_97 * liter;
        break;
    default:
        perror("汽油号不合法");
        return INVALID_PETROL_NUMBER;
    }

    // 折扣
    if (type == 'm')
    {
        money *= (1 - M_PRICE_OFF);
    }
    else if (type == 'e')
    {
        money *= (1 - E_PRICE_OFF);
    }

    printf("%.2f", money);

    return 0;
}