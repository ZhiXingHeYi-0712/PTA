#include<stdio.h>
#include<string.h>
int main() {
    char s[] = "I Love GPLT";
    for (int i = 0; i < strlen(s); i++) {
        printf("%c\n", s[i]);
    }
    return 0;
}