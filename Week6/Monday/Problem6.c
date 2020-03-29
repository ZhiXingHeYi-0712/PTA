#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define INPUT_ERROR 1

// 李浩 201911039093
int main()
{
    int target;
    int guessNumber;
    int times = 1;
    int maxTime;

    if (scanf("%d %d", &target, &maxTime) < 0)
    {
        return 1;
    }

    while (1)
    {
        if (scanf("%d", &guessNumber) < 0)
        {
            perror("Err.");
            return INPUT_ERROR;
        }
        if (guessNumber < 0)
        {
            puts("Game Over");
            return 0;
        }

        if (guessNumber > target)
        {
            if (times == maxTime)
            {
                puts("Too big");
                puts("Game Over");
                return 0;
            }
            puts("Too big");
        } 
        else if (guessNumber < target)
        {
            if (times == maxTime)
            {
                puts("Too small");
                puts("Game Over");
                return 0;
            }
            puts("Too small");
        }
        else
        {
            if (times == 1)
            {
                puts("Bingo!");
            }
            else if (times <= 3)
            {
                puts("Lucky You!");
            }
            else
            {
                puts("Good Guess!");
            }
            return 0;
        }
        times++;
    }
}
