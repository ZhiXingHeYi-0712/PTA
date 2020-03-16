#include <stdio.h>
#include <stdlib.h>

#define INPUT_ERROR 1

int mix2minute(int mix);
int minute2mix(int minute);
char *convertTimeWithTopZero(int time);

    int main()
{
    int depart, arrive;
    if (scanf("%d %d", &depart, &arrive) < 0)
    {
        perror("Err.");
        return INPUT_ERROR;
    }
    int difference = minute2mix(mix2minute(arrive) - mix2minute(depart));
    char* hour = convertTimeWithTopZero(difference / 100);
    char* minutes = convertTimeWithTopZero(difference % 100);

    printf("%s:%s", hour, minutes);

    free(hour);
    free(minutes);

    return 0;
}

char * convertTimeWithTopZero(int time) {
    char * result = calloc(sizeof(char), 3);
    *result =  time / 10 + '0';
    *(result + 1) = (char) time % 10 + '0';
    return result;      // free!!!
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