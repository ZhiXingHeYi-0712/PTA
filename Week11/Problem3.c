#include <stdio.h>
#include <stdlib.h>

void hanoi(int layers, char *from, char *to, char *tmp);
void move(int num, char *from, char *to);

int main()
{
    int layers;
    char from[32], to[32], tmp[32];
    scanf("%d\n%s %s %s", &layers, from, to, tmp);
    hanoi(layers, from, to, tmp);
}

void hanoi(int layers, char *from, char *to, char *tmp)
{
    if (layers == 1)
    {
        move(1, from, to);
    }
    else
    {
        hanoi(layers - 1, from, tmp, to);
        move(layers, from, to);
        hanoi(layers - 1, tmp, to, from);
    }
}

void move(int num, char *from, char *to)
{
    printf("%d: %s -> %s\n", num, from, to);
}