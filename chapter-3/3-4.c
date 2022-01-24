#include <stdbool.h>
#include <string.h>

int positiveRemainder(int dividend, int divisor) {
    if (dividend >= 0) {
        return dividend % divisor;
    }
    else {
        return ((dividend / divisor) * divisor) - dividend;
    }
}

void reverse(char * s) {
    int temp;
    int workingLen = strlen(s) - 1;
    for (int i = 0; i <= workingLen/2; i++) {
        temp = s[i];
        s[i] = s[workingLen - i];
        s[workingLen - i] = temp;
    }
}

void itoa(int n, char* s) {
    int i = 0;
    bool sign = n < 0;
    do {
        s[i++] = positiveRemainder(n, 10) + '0';
    } while ((n /= 10) != 0);
    if (sign) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int a = INT_MIN;
    int b = INT_MAX;
    char * s = malloc(sizeof(char) * 100);
    itoa(a, s);
    printf("%s\n", s);
    itoa(b, s);
    printf("%s\n", s);
    free(s);
    return 0;
}