#include <stdio.h>
#include <stdlib.h>

int mix2minute(int mix);
int minute2mix(int minute);

int main()
{
    int time, time_change;
    if (scanf("%d %d", &time, &time_change) < 0)
    {
        perror("Err.");
        return 1;
    }

    int changed_time = mix2minute(time) + time_change;

    printf("%d", minute2mix(changed_time));

    return 0;
}

int mix2minute(int mix)
{
    int hour = mix / 100;
    int minute = mix - hour * 100;
    return hour * 60 + minute;
}

int minute2mix(int minute)
{
    int hour = minute / 60;
    minute = minute - hour * 60;
    return hour * 100 + minute;
}